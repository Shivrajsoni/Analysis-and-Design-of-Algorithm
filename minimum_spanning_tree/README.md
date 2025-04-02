## Working of the Prim’s Algorithm
- Step 1: Determine an arbitrary vertex as the starting vertex of the MST. We pick 0 in the below diagram.
- Step 2: Follow steps 3 to 5 till there are vertices that are not included in the MST (known as fringe vertex).
- Step 3: Find edges connecting any tree vertex with the fringe vertices.
- Step 4: Find the minimum among these edges.
- Step 5: Add the chosen edge to the MST. Since we consider only the edges that connect fringe vertices with the rest, we never get a cycle.
- Step 6: Return the MST and exit


## How to find MST using Kruskal’s algorithm?
- Below are the steps for finding MST using Kruskal’s algorithm:

- Sort all the edges in a non-decreasing order of their weight. 
- Pick the smallest edge. Check if it forms a cycle with the spanning tree formed so far. If the cycle is not formed, include this edge. Else, discard it. 
- Repeat step 2 until there are (V-1) edges in the spanning tree.
