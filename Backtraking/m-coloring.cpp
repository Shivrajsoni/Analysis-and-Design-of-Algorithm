#include <iostream>
#include <vector>
using namespace std;

class GraphColoring {
public:
  bool isSafe(vector<int> adj[], int col, int vertex, vector<int> &color) {
    for (auto it : adj[vertex]) {
      if (color[it] != -1 && col == color[it])
        return false;
    }
    return true;
  }

  bool canColor(int vertex, int m, vector<int> adj[], vector<int> &color) {
    if (vertex == color.size())
      return true;

    for (int i = 0; i < m; i++) {
      if (isSafe(adj, i, vertex, color)) {
        color[vertex] = i;
        if (canColor(vertex + 1, m, adj, color)) {
          return true;
        }
        color[vertex] = -1;
      }
    }
    return false;
  }

  bool graphColoring(int V, vector<vector<int>> &edges, int m) {
    vector<int> adjlist[V];

    for (auto i : edges) {
      adjlist[i[0]].push_back(i[1]);
      adjlist[i[1]].push_back(i[0]);
    }
    vector<int> color(V, -1);
    return canColor(0, m, adjlist, color);
  }
};

int main() {
  GraphColoring g;
  int m = 3;
  int V = 4;
  vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 3}, {2, 3}};
  cout << (g.graphColoring(V, edges, m) ? " true " : " false ") << endl;
}
