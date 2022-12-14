# -*- coding: utf-8 -*-
"""
Undergraduates - S3
Examples of graphs (from tutorial)

"""

from algopy import graph, graphmat

G1 = graph.Graph(9, True)
G1.adjlists = [[1, 1, 1, 6, 2], 
               [3, 3], 
               [6, 8], 
               [6], 
               [3], 
               [2, 6], 
               [3, 4], 
               [6, 5, 8], 
               [8]]


G1mat = graphmat.GraphMat(9, True)
G1mat.adj = [[0, 3, 1, 0, 0, 0, 1, 0, 0],
             [0, 0, 0, 2, 0, 0, 0, 0, 0],
             [0, 0, 0, 0, 0, 0, 1, 0, 1],
             [0, 0, 0, 0, 0, 0, 1, 0, 0],
             [0, 0, 0, 1, 0, 0, 0, 0, 0],
             [0, 0, 1, 0, 0, 0, 1, 0, 0],
             [0, 0, 0, 1, 1, 0, 0, 0, 0],
             [0, 0, 0, 0, 0, 1, 1, 0, 1],
             [0, 0, 0, 0, 0, 0, 0, 0, 1]]


G2 = graph.Graph(9, False)
G2.adjlists = [[2, 1, 1, 1],
               [0, 0, 0, 3, 3],
               [0],
               [1, 1],
               [5, 6, 7],
               [4, 7, 8],
               [4, 7],
               [4, 6, 5, 8, 7],
               [7, 5]]
 
G2mat = graphmat.GraphMat(9, False)
G2mat.adj = [[0, 3, 1, 0, 0, 0, 0, 0, 0],
             [3, 0, 0, 2, 0, 0, 0, 0, 0],
             [1, 0, 0, 0, 0, 0, 0, 0, 0],
             [0, 2, 0, 0, 0, 0, 0, 0, 0],
             [0, 0, 0, 0, 0, 1, 1, 1, 0],
             [0, 0, 0, 0, 1, 0, 0, 1, 1],
             [0, 0, 0, 0, 1, 0, 0, 1, 0],
             [0, 0, 0, 0, 1, 1, 1, 1, 1],
             [0, 0, 0, 0, 0, 1, 0, 1, 0]]
             
# with labels (only Graph) 
 
G3 = graph.Graph(6, True, labels = ['algo', 'maths', 'prog', 'archi', 'élec', 'phys'])
G3.addedge(1, 0)
G3.addedge(0, 2)
G3.addedge(2, 1)
G3.addedge(2, 3)
G3.addedge(3, 2)
G3.addedge(1, 3)
G3.addedge(1, 4)
G3.addedge(4, 3)
G3.addedge(5, 4)
G3.addedge(1, 5)
G3.addedge(3, 0)
