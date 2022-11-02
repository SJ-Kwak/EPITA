from re import L
from turtle import right
from btree_ex import *
from algopy import btree

def __btree2list(B, l):
    if len(B.children) > 0:
        for i in range(B.nbkeys):
            __btree2list(B.children[i], l)
            l.append(B.keys[i])
        __btree2list(B.children[B.nbkeys], l)
    else:
        for k in B.keys:
            l.append(k)

def btree2list(B):
    l = []
    if B:
        __btree2list(B,l)
    return l

def minBTree(B):
    while len(B.children) > 0:
        B = B.children[0]   # left-most child
    return B.keys[0]

def maxBTree(B):
    while len(B.children) > 0:
        B = B.children[B.nbkeys]
    return B.keys[B.nbkeys - 1] # the last node (array length: nb, last node: nb - 1)

def __binarySearch(l, x, left, right):
    """ returns the position wehre x is or might be in l (left, right[
    """
    if right <= left:
        return right
    else:
        mid = left + (right - left) // 2 # int division
        if x == l[mid]: # mid
            return mid
        elif x < l[mid]:
            return __binarySearch(l, x, left, mid)  # [left, mid[
        else:
            return __binarySearch(l, x, mid+1, right)   # [mid+1, right[

def binarySearch(l, x): # will be used in search, insertion and deletion
    """ returns the position where x is or might be in l
    """
    return __binarySearch(l, x, 0, len(l))

def __searchBTree(B, x):
    i = binarySearch(B.keys, x)
    if i < B.nbkeys and B.keys[i] == x:
        return (B, i)
    elif B.children == []:
        return None
    else:
        return __searchBTree(B.children[i], x)

def searchBTree(B, x):  # returns None if not B else __searchBTree
    if B == None:
        return None
    else:
        return __searchBTree(B, x)

def split(B, i):
    """
    splits the child i of B
    conditions:
    - B is a non-empty tree and its root is not a 2t-node
    - the child i of B exists and its root is a 2t-node
    There is no need to return B, the root (the reference) does not change!
    """
    mid = B.degree - 1
    l = B.children[i]
    r = btree.BTree()
    # keys of the child
    (l.keys, x, r.keys) = (l.keys[:mid], l.keys[mid], l.keys[mid+1:])
    # children of the child
    if l.children == []:
        r.children = []
    else:
        (l.children, r.children) = (l.children[:mid+1], l.children[mid+1:])
    # root
    B.keys.insert(i, x)
    B.children.insert(i+1, r)

def __insert(B, k):
    i = binarySearch(B.keys, k)
    if i < B.nbkeys and k == B.keys[i]:
        raise Exception("ch ch")
    elif B.children == []:
        B.keys.insert(i, k)
    else:
        if B.children[i].nbkeys == 2*B.nbkeys - 1:
            if B.children[i].keys[B.degree - 1] == k:
                raise Exception("None")
            split(B, i)
            if k > B.keys[i]:
                i += 1
        __insert(B.children[i], k)

def insert(B, k):
    if B == None:
        B = btree.BTree([k])
    else:
        if B.nbkeys == B.degree * 2 - 1:
            B = btree.BTree(None, [B])
            split(B, 0)
        __insert(B, k)
    return B

def leftRotation(B, i):
    """makes a rotation from child i+1 to child i
    conditions:
    - B exists
    - the child i exists and its root is not a 2t-node
    - the child i+1 exists and its root is not a t-node
    """
    l = B.children[i]
    r = B.children[i+1]
    l.keys.append(B.keys[i])
    B.keys[i] = r.keys.pop(0)
    if r.children != []:
        l.children.append(r.children.pop(0))

def rightRotation(B, i):
    """makes a rotation from child i-1 to child i
    conditions:
    - B exists
    - the child i exists and its root is not a 2t-node
    - the child i-1 exists and its root is not a t-node
    """
    l = B.children[i-1]
    r = B.children[i]
    r.keys.insert(0, B.keys[i-1])
    B.keys[i-1] = l.keys.pop()
    if l.children != []:
        r.children.insert(0, l.children.pop())

def merge(B, i):
    """merge B's children i and i+1 into child i
    conditions:
    - B exists and its root is not a t-node
    - children i and i+1 both exist and their roots are t-nodes
    """
    l = B.children[i]
    r = B.children.pop(i+1)
    l.keys.append(B.keys.pop())
    l.keys += r.keys
    l.children += r.children

def __delete(B, k):     # B exists and isn't a t-node
    i = binarySearch(B.keys, k)
    if B.children != []:    # not a leaf
        if i < B.nbkeys and k == B.keys[i]:     # x <- root
            if B.children[i].nbkeys > B.degree - 1:
                B.keys[i] = maxBTree(B.children[i])
                return __delete(B.children[i], B.keys[i])
            elif B.children[i+1].nbkeys > B.degree - 1:
                B.keys[i] = minBTree(B.children[i+1])
                return __delete(B.children[i+1], B.keys[i])
            else:
                merge(B, i)
                return __delete(B.children[i], k)
        else:   # not in the key
            if B.children[i].nbkeys == B.degree - 1:    # if child's root is not a t-node
                if i < B.nbkeys and B.children[i+1].nbkeys > B.degree - 1:
                    leftRotation(B, i)
                elif i > 0 and B.children[i-1].nbkeys > B.degree - 1:
                    rightRotation(B, i)
                else:
                    if i == B.nbkeys:
                        i -= 1
                    merge(B, i)
            return __delete(B.children[i], k)
    else:   # leaf
        if i < B.nbkeys and B.keys[i] == k:
            B.keys.pop(i)
            return True
        else:
            return False

def delete(B, k):
    if B != None:
        __delete(B, k)
        if B.nbkeys > 0:
            return B
        elif B.children != []:
            return B.children[0]
    return None