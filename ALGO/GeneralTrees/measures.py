# size
def size(T):
    s = 1
    for c in T.children:
        s += size(c)
    return s

def sizeAsBin(B):
    s = 1
    c = B.child
    while c is not None:
        s += sizeAsBin(c)
        c = c.sibling
    return s


# height
def height(T):
    h = 0
    for c in T.children:
        h = max(h, height(c) + 1)   # not the accumulation. do not need addition
    return h                        # 1: for the root node

def heightAsBin(B):
    h = 0
    c = B.child
    while c is not None:
        h = max(h, heightAsBin(c) + 1) # 1: need to compare the height including root node (first level)
        c = c.sibling
    return h
