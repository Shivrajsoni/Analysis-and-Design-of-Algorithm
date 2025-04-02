#include<bits/stdc++.h>
#include<queue>

using namespace std;
class Solution {
  public:
  int spanning_tree(int V, vector<vector<int,int>>adj[]){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int>vis(V,0);
    int sum = 0;
    // wt,node
    pq.push({0,0});

    while (!pq.empty())
    {
      auto it = pq.top();
      pq.pop();

      int node = it.second;
      int weight = it.first;

      if(vis[node]==1)
      continue;

      vis[node]=1;
      sum+=weight;
      for(auto it: adj[node]){
        int adjNode = it[0];
        int edW = it[1];
        
        if(!vis[adjNode]){
          pq.push({edW,adjNode});
        }

      }
    }  
    return sum;
  }

};


int main(){
    int V = 3, E = 3, S = 2;
    vector<vector<int>> adj[V];
    vector<vector<int>> edges;
    vector<int> v1{1, 1}, v2{2, 6}, v3{2, 3}, v4{0, 1}, v5{1, 3}, v6{0, 6};
    int i = 0;
    adj[0].push_back(v1);
    adj[0].push_back(v2);
    adj[1].push_back(v3);
    adj[1].push_back(v4);
    adj[2].push_back(v5);
    adj[2].push_back(v6);
  
  Solution obj;

  int ans = obj.spanning_tree(V,adj);

  cout<<"The sum of minimum Spanning tree is : "<<ans<<endl;

  return 0;
}
