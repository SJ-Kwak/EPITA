from tree_ex import *
from algopy.queue import Queue

def DFS(T):
    # if T.nbchildren == 0:
    #     # leaf
    #     return -1
    # else:
    print(T.key)
    if T.nbchildren != 0:
        # preorder
        for i in range(T.nbchildren - 1):   # nb - 1: loop Till children has intermediate
            DFS(T.children[i])
            # intermediate
        DFS(T.children[T.nbchildren - 1])   # last children does not have intermediate
        # postorder


def DFS_TreeAsBin(B):
    # if B.child == None:
    #     # leaf
    #     return -1
    # else:
    print(B.key)
    if B.child != None:
        # preorder
        c = B.child
        while c.sibling != None:
            DFS_TreeAsBin(c)
            # intermediate
            c = c.sibling
        DFS_TreeAsBin(c)
        # postorder

# marker for the end level (None) is added in the queue
def BFS(T):
    q = Queue()
    q.enqueue(T)
    q.enqueue(None)     # to detect level changes
    current = 0
    width = 0
    while not q.isempty():  # while in the current level
        T = q.dequeue()
        print(T)
        if T == None:
            width = max(current, width)
            if not q.isempty():
                q.enqueue(None)
                current = 0
        else:
            for c in T.children:
                q.enqueue(c)
            current += 1
    return width
BFS(T2)
# 2 queues (next, current)
def BFS_TreeAsBin(B):
    (current, width) = (0, 0)
    q_next = Queue()
    q_cur = Queue()
    q_cur.enqueue(B)
    while not q_cur.isempty():
        current += 1
        B = q_cur.dequeue()
        c = B.child
        while c:
            q_next.enqueue(c)
            c = c.sibling
        if q_cur.isempty():
            (width, current) = (max(width, current), 0)
            (q_cur, q_next) = (q_next, q_cur)
    return width