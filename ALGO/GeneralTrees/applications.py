from tree_ex import *
from algopy.queue import Queue
from algopy.tree import Tree
from algopy.display import display, displayAsBin

def to_linear(T):
    s = "(" + str(T.key)
    for c in T.children:
        s += to_linear(c)
    return s + ")"

def to_linearAsBin(B):
    s = "(" + str(B.key)
    c = B.child
    while c:
        s += to_linearAsBin(c)
        c = c.sibling
    return s + ")"

def dot(T):
    q = Queue()
    q.enqueue(T)
    s = "graph {\n"
    while not q.isempty():
        current = q.dequeue()
        for c in current.children:
            s += str(current.key) + " -- " + str(c.key) + "\n"
            q.enqueue(c)
    return s + "}"

def __dotAsBin(B):
    s = ""
    q = Queue()
    q.enqueue(B)
    while not q.isempty():
        current = q.dequeue()
        c = current.child
        while c:
            s += str(current.key) + " -- " + str(c.key) + "\n"
            q.enqueue(c)
            c = c.sibling
    return s

def dotAsBin(B):
    return "graph {\n" + __dotAsBin(B) + "}"

def __morechildren(T):
    if T.nbchildren == 0:
        return -1
    else:
        for c in T.children:
            result = __morechildren(c)
            if result > 0 and result <= T.nbchildren:
                return 0
        return T.nbchildren
    
def morechildren(T):
    return __morechildren(T) > 0

def __nbchildren(B):
    k = 0
    c = B.child
    while c:
        k += 1
        c = c.sibling
    return k

def __morechildrenAsBin(B):
    nb = __nbchildren(B)
    # if nb == 0:
    #     return -1
    # else:
    c = B.child
    while c and nb >= 0:
        result = __morechildrenAsBin(c)
        if result > 0 and result <= nb:
            return -1
        c = c.sibling
    return nb

def morechildrenAsBin(B):
    return __morechildrenAsBin(B) > 0

def __averageArity(T):
    if T.nbchildren == 0:
        return (0,0)
    else:
        inter = 1
        nb = T.nbchildren
        for c in T.children:
            (nb_i, nb_c) = __averageArity(c)
            inter += nb_i
            nb += nb_c
        return (inter, nb)

def averageArity(T):
    (inter, nb) = __averageArity(T)
    if inter != 0:
        return nb / inter
    else:
        return 0

def __averageArityAsBin(B):
    if B.child != None:
        c = B.child
        (inter, nb) = (1,0)
        while c:
            (inter_c, nb_c) = __averageArityAsBin(c)
            nb += nb_c + 1
            inter += inter_c
            c = c.sibling
        return (inter, nb)
    else:
        return (0,0)

def averageArityAsBin(B):
    (inter, nb) = __averageArityAsBin(B)
    if inter != 0:
        return nb / inter
    else:
        return 0

def same(T, B):
    if T.key != B.key:
        return False
    else:
        i = 0
        c = B.child
        while c != None and same(T.children[i], c):
            c = c.sibling
            i += 1
        return i == T.nbchildren and c == None

def same2(T,B):
    if T.key != B.key:
        return False
    else:
        cB = B.child
        for cT in T.children:
            if cB == None or not same(cT, cB):
                return False
            cB = cB.sibling
        return cB == None
    
def TAB_to_tree(B):
    T = Tree(B.key, None)
    c = B.child
    while c:
        T.children.append(TAB_to_tree(c))
        c = c.sibling
    return T

def tree_to_TAB(T):
    B = TreeAsBin(T.key, None, None)
    if T.nbchildren != 0:
        B.child = tree_to_TAB(T.children[0])
        last = B.child
        for i in range(1, T.nbchildren):
            last.sibling = tree_to_TAB(T.children[i])
            last = last.sibling
    return B

def tree_to_TAB2(T):
    B = TreeAsBin(T.key, None, None)
    fc = None
    for i in range(T.nbchildren - 1, -1, -1):
        c = tree_to_TAB2(T.children[i])
        c.sibling = fc
        fc = c
    B.child = fc
    return B

def __from_linear(s, i=0):
    i += 1
    key = ""
    while s[i] != "(" and s[i] != ")":
        key += s[i]
        i += 1
    T = Tree(int(key), [])
    while s[i] != "(":
        (c, i) = __from_linear(s, i)
        T.children.append(c)
    return (T, i+1)

def from_linear(s):
    (T, _) = __from_linear(s)
    return T

def load(filename):
    """Build a new tree from a text file containing the _linear representation_.

    Args:
        filename (str): File to load.

    Returns:
        Tree: New tree.

    Raises:
        FileNotFoundError: If file does not exist. 

    """        
    # Open file and get full content
    file = open(filename, 'r')
    content = file.read()
    # Remove all whitespace characters for easier parsing
    content = content.replace('\n', '').replace('\r', '') \
                     .replace('\t', '').replace(' ', '')
    file.close()
    # Parse content and return tree
    return from_linear(content)


