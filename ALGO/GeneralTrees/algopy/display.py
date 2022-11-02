def display(T):
    print("<", T.key, end = " ")
    for c in T.children:
        print(",", end = " ")
        display(c)
    print(">")

def displayAsBin(B):
    print("<", B.key, end = " ")
    c = B.child
    while c != None:
        print(",", end = " ")
        displayAsBin(c)
        c = c.sibling
    print(">")