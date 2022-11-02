from algopy.tree import Tree, TreeAsBin

T = Tree(1,
        [Tree(2, None), 
        Tree(3, [Tree(5, None)]), 
        Tree(4, None)])

B = TreeAsBin(1,
        TreeAsBin(2, None, 
        TreeAsBin(3, TreeAsBin(5, None, None), 
        TreeAsBin(4, None, None))), None)

# the first example in tutorial
T1 = Tree(15,
          [Tree(3,[Tree(-6),Tree(10)]),
           Tree(8,[Tree(11,[Tree(0),Tree(4)]), Tree(2),Tree(5)]),
           Tree(9)])

# figure 2 (for BFS -> keys in order)
T2 = Tree(1,
          [Tree(2,[Tree(6),Tree(7,[Tree(14,[Tree(18)]),Tree(15)])]),
           Tree(3,[Tree(8)]),
           Tree(4,[Tree(9),Tree(10),Tree(11,[Tree(16),Tree(17)]),Tree(12)]),
           Tree(5,[Tree(13)])])

# ex for dot (ex 3.1)
T3 = Tree(4,[Tree(8,[Tree(0),Tree(4),Tree(5)]),
             Tree(12,[Tree(-4), Tree(0), Tree(5), Tree(8)])])

# another tree...
T4 = Tree(12,[Tree(2,[Tree(25),Tree(6),Tree(-7)]),
              Tree(0,[Tree(18,[Tree(1),Tree(8)]),Tree(9)]),
              Tree(4,[Tree(3),Tree(11)])])     

# ex for more children
T5 = Tree(1, [Tree(2,[Tree(4),Tree(5),Tree(6)]),
              Tree(3,[Tree(7),Tree(8)])])

# ex for more children
T6 = Tree(1, [Tree(2,[Tree(4),Tree(5),Tree(6)]),
              Tree(3,[Tree(7),Tree(8),Tree(9)])])

# same trees in first child - right sibling implementation

B1 = TreeAsBin(15,
               TreeAsBin(3,TreeAsBin(-6,None,TreeAsBin(10)),
                         TreeAsBin(8,TreeAsBin(11,TreeAsBin(0,None,TreeAsBin(4)),TreeAsBin(2,None,TreeAsBin(5))),
                                   TreeAsBin(9))),None)              
                                   
B2 = TreeAsBin(1,
         TreeAsBin(2,TreeAsBin(6,None,TreeAsBin(7,TreeAsBin(14,TreeAsBin(18),TreeAsBin(15)),None)),
         TreeAsBin(3,TreeAsBin(8),
         TreeAsBin(4,TreeAsBin(9,None,TreeAsBin(10,None,TreeAsBin(11,TreeAsBin(16,None,TreeAsBin(17)),TreeAsBin(12)))),
         TreeAsBin(5,TreeAsBin(13),None)))),None)

B3 = TreeAsBin(4,
               TreeAsBin(8,
                         TreeAsBin(0,None,TreeAsBin(4, None, TreeAsBin(5, None, None))),
                         TreeAsBin(12, TreeAsBin(-4,None, TreeAsBin(0, None, TreeAsBin(5, None, TreeAsBin(8,None,None)))))),
                None)
                                        
B4 = TreeAsBin(12,TreeAsBin(2,TreeAsBin(25,None,TreeAsBin(6,None,TreeAsBin(-7))),TreeAsBin(0,TreeAsBin(18,TreeAsBin(1,None,TreeAsBin(8)),TreeAsBin(9)),TreeAsBin(4,TreeAsBin(3,None,TreeAsBin(11)),None))),None)

B5 = TreeAsBin(1,
               TreeAsBin(2,TreeAsBin(4,None,TreeAsBin(5,None,TreeAsBin(6,None,None))),
               TreeAsBin(3,TreeAsBin(7,None,TreeAsBin(8,None,None)),None)),
               None)

B6 = TreeAsBin(1,
               TreeAsBin(2,TreeAsBin(4,None,TreeAsBin(5,None,TreeAsBin(6,None,None))),
               TreeAsBin(3,TreeAsBin(7,None,TreeAsBin(8,None,TreeAsBin(9,None,None))),None)),
               None)