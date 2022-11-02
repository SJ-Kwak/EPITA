class Tree:
    def __init__(self, key = None, children = None):
        self.key = key
        if children == None:
            self.children = []
        else:
            self.children = children

    @property
    def nbchildren(self):
        return len(self.children)

class TreeAsBin:
    def __init__(self, key, child = None, sibling = None):
        self.key = key
        self.child = child
        self.sibling = sibling