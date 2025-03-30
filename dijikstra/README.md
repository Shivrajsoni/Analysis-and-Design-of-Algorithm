# Dijkstra's Algorithm Using Priority Queue

## 🚀 Introduction
Dijkstra's Algorithm is a **greedy** algorithm used to find the **shortest path** from a source node to all other nodes in a weighted graph. This implementation uses a **priority queue (min-heap)** for efficient shortest path computation.

## 📌 Features
- **Efficient**: Uses a priority queue (Min-Heap) to optimize time complexity to **O((V + E) log V)**.
- **Handles Weighted Graphs**: Works with both directed and undirected weighted graphs.
- **No Negative Weights**: Cannot handle negative edge weights (use Bellman-Ford for that).

---

## 🛠️ Implementation
### **1. Function Definition**
```cpp
vector<int> dijkstra_using_priority_queue(int V, vector<pair<int, int>> adj[], int S) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(V, INT_MAX);  // Initialize distances to infinity

    dist[S] = 0;
    pq.push({0, S});

    while (!pq.empty()) {
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto it : adj[node]) {
            int adjNode = it.first;
            int edgeWeight = it.second;

            if (dis + edgeWeight < dist[adjNode]) {
                dist[adjNode] = dis + edgeWeight;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
}
```

### **2. Graph Representation**
- The graph is represented as an **adjacency list** using an array of vectors.
- Each **node** stores `{neighbor, weight}` as pairs.

```cpp
vector<pair<int, int>> adj[V];
```

---

## 📌 How to Use
### **1. Add Edges to the Graph**
```cpp
void addEdge(vector<pair<int, int>> adj[], int u, int v, int w) {
    adj[u].push_back({v, w});
    adj[v].push_back({u, w}); // Comment this for a directed graph
}
```

### **2. Run Dijkstra’s Algorithm**
```cpp
int main() {
    int V = 5; // Number of vertices
    vector<pair<int, int>> adj[V];

    addEdge(adj, 0, 1, 10);
    addEdge(adj, 0, 4, 20);
    addEdge(adj, 1, 2, 30);
    addEdge(adj, 1, 3, 40);
    addEdge(adj, 2, 3, 50);

    int source = 0;
    vector<int> shortestPaths = dijkstra_using_priority_queue(V, adj, source);

    cout << "Shortest distances from source " << source << ":\n";
    for (int i = 0; i < V; i++) {
        cout << "Node " << i << " -> Distance: " << shortestPaths[i] << endl;
    }
    return 0;
}
```

---

## 📈 Complexity Analysis
- **Time Complexity**: `O((V + E) log V)` (using min-heap priority queue)
- **Space Complexity**: `O(V + E)` (storing graph and priority queue)

---

## 🏆 Example Output
```
Shortest distances from source 0:
Node 0 -> Distance: 0
Node 1 -> Distance: 10
Node 2 -> Distance: 40
Node 3 -> Distance: 50
Node 4 -> Distance: 20
```

---

## 🔥 Advantages
✅ Faster than **Bellman-Ford** for positive weights.  
✅ Works well with **dense graphs** using adjacency matrix.  
✅ Easy to implement using **priority queue**.  

---

## ❌ Limitations
🚫 **Cannot handle negative weights** (Use **Bellman-Ford** for that).  
🚫 **Fails with negative cycles** (Use **Floyd-Warshall** for all-pairs shortest paths).  

---

## 📚 References
- [Dijkstra’s Algorithm - GeeksforGeeks](https://www.geeksforgeeks.org/dijkstra-algorithm/)  
- [Priority Queue in C++ STL](https://www.cplusplus.com/reference/queue/priority_queue/)

