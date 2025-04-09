

- A DP is an algorithmic technique which is usually based on a recurrent formula and one (or some) starting states. A sub-solution of the problem is constructed from previously found ones. DP solutions have a polynomial complexity which assures a much faster running time than other techniques like backtracking, brute-force etc.

## MultiStage Graph
A multistage graph is a directed weighted graph where nodes are divided into multiple stages, and the goal is to find the shortest (or longest) path from a source node in the first stage to a destination node in the last stage. This problem is efficiently solved using Dynamic Programming (DP).

### Steps:

- 1.The algorithm works by calculating the shortest cost from each node to the destination, starting from the last stage and moving backward (i.e., using backward dynamic programming).

- 2.For each node, we check all outgoing edges and select the one with the minimum cost to the destination.

- 3.Finally, we get the shortest path from the source to destination by following the choices made.

### Time Complexity:O(V^2)

## All pair Shortest Path(floyd Warshall Algorithmic)

The All-Pairs Shortest Path (APSP) problem involves finding the shortest path between every pair of nodes in a weighted graph. This is useful in various real-world applications such as network routing, transportation planning, and urban navigation systems.

### Steps:

- 1.It initializes a distance matrix A[i][j], where A[i][j] is the weight of the edge from vertex i to j, or infinity if no edge exists.

- 2.It then considers each vertex k as an intermediate point, and checks whether the path from i to j can be made shorter by going through k.

- 3.For every pair of vertices (i, j), it updates: A[i][j] = min(A[i][j], dist[i][k] + A[k][j])

- 4.This is done for all vertices k = 0 to V-1, where V is the number of vertices.

- 5.After the algorithm finishes, A[i][j] contains the shortest distance from vertex i to j.

### Time Complexity:O(n^3)

