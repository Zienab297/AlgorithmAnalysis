def prim(graph, start):
    mst = set()
    visited = {start}
    nodes, edges = graph

    while len(visited) != len(nodes):
        possible_edges = (i for i in edges if i[0] in visited and i[1] not in visited)
        cheapest_edge = min(possible_edges, key=lambda i: i[2])
        mst.add(cheapest_edge)
        visited.add(cheapest_edge[1])

    return mst


if __name__ == '__main__':
    nodes = range(1, 5)
    edges = [ (1, 2, 4),
            (2, 1, 4),
            (1, 8, 8),
            (8, 1, 8),
            (2, 8, 11),
            (8, 2, 11),
            (2, 3, 8)
            ]
    graph = (nodes, edges)      
    mst = prim(graph, 1)
    cost = sum(weigth for _, __, weigth in mst)
    print(cost)
    print(mst)
