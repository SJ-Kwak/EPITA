__license__ = 'Nathalie (c) EPITA'
__docformat__ = 'reStructuredText'
__revision__ = '$Id: prefixtrees.py 2022-10-03'

"""
Prefix Trees homework
2022-10 - S3
@author: seojin.kwak
"""

from algopy import ptree

###############################################################################
# Do not change anything above this line, except your login!
# Do not add any import

##############################################################################
## Measure

def count_words(T):
    """ count words in the prefix tree T (ptree.Tree)
    return type: int
    """
    
    n = 0
    if(T.key[1]):
        n += 1
    for c in T.children:
        n += count_words(c)
    return n

def longest_word_length(T):
    """ longest word length in the prefix tree T (ptree.Tree)
    return type: int    
    """
    
    h = 0
    for c in T.children:
        h = max(h, longest_word_length(c)+1)
    return h

def __average_length(T, length):
    """ subfunction for getting average word length in the prefix tree T (ptree.Tree)
    return type: float
    """

    l = 0
    if T.key[1]:
        l += length
    for c in T.children:
        l += __average_length(c, length+1)
    return l
    

def average_length(T):
    """ average word length in the prefix tree T (ptree.Tree)
    return type: float
    """

    length = __average_length(T, 0)
    words = count_words(T)
    return length / words 

###############################################################################
## search and list
def __word_list(T, word):
    """ subfunction for generating the word list of the prefix Tree T
    """

    l = []
    if T:
        word += T.key[0]
        if(T.key[1]):
            l.append(word)
        for c in T.children:
            l += __word_list(c, word)
    return l

def word_list(T):
    """ generate the word list of the prefix tree T (ptree.Tree)
    return type: str list
    """
    
    return __word_list(T, "")

def search_word(T, w):
    """ search for the word w (str) not empty in the prefix tree T (ptree.Tree)
    return type: bool
    """
    
    for c in word_list(T):
        if (c == w):
            return True
    return False
    
def completion(T, prefix):
    """ generate the list of words in the prefix tree T (ptree.Tree) with a common prefix 
    return type: str list    
    """
    
    pre = prefix.lower()
    result = []
    l = word_list(T)
    for w in l:
        if len(pre) <= len(w):
            check = True
        else:
            check = False
        i = 0
        while i < len(pre) and check:
            if pre[i] != w[i]:
                check = False
            i += 1
        if check:
            result.append(w)
    return result


###############################################################################
## Build

def build_lexicon(T, filename):
    """ save the tree T (ptree.Tree) in the new file filename (str)
    """
    
    l = word_list(T)
    file = open(filename, "w")
    for c in l:
        file.write(c + "\n")
    file.close()


def __add_word(T, w, idx):
    """ subfunction for adding the word w (str) not empty in the tree T (ptree.Tree)
    """

    idx += 1
    if idx < len(w):
        found = False
        i = 0
        for c in T.children:
            if c.key[0] == w[idx]:
                __add_word(c, w, idx)
                found = True
                break
            if c.key[0] > w[idx]:
                tr = ptree.Tree((w[idx], idx == len(w)), [])
                __add_word(tr, w, idx)
                T.children.insert(i, tr)
                found = True
                break
            i += 1
        if found != True and idx < len(w):
            tr = ptree.Tree((w[idx], idx == len(w)), [])
            __add_word(tr, w, idx)
            T.children.append(tr)
    if idx == len(w):
        T.key = (T.key[0], True)


def add_word(T, w):
    """ add the word w (str) not empty in the tree T (ptree.Tree)
    """

    __add_word(T, w, -1)


def build_tree(filename):
    """ build the prefix tree from the file of words filename (str)
    return type: ptree.Tree
    """
    
    file = open(filename, "r")
    T = ptree.Tree(('', False))
    for w in file.readlines():
        add_word(T, w.strip())
    file.close()
    return T
