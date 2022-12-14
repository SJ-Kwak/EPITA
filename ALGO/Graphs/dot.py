from ex_graphs import G1, G2, G1mat, G2mat

def todot(G):
    """Dot format of graph.

    Args:
        Graph

    Returns:
        str: String storing dot format of graph.

    """

    if G.directed:
        dot = "digraph {\n"
        line = " -> "
    else:
        dot = "graph {\n"
        line = " -- "
    
    for i in range(G.order):
        for j in range(len(G.adjlists[i])):
            dot += ' ' + str(i) + line + str(G.adjlists[i][j]) + '\n'
    dot += "}"
    return dot

def todotMat(G):
    """Dot format of graph.

    Args:
        GraphMat

    Returns:
        str: String storing dot format of graph.

    """

    if G.directed:
        dot = "digraph {\n"
        line = " -> "
    else:
        dot = "graph {\n"
        line = " -- "
    
    for i in range(G.order):
        for j in range(G.order):
            if G.adj[i][j] != 0:
                dot += ' ' + str(i) + line + str(G.adj[i][j]) + '\n'
    dot += "}"
    return dot