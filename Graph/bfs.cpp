#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        
        unordered_map<int, bool> visited;
        vector<int> ans;
        
        queue<int> q;
        
        q.push(0);
        visited[0] = true;
        
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            
            ans.push_back(frontNode);
            
            for(auto i: adj[frontNode]){
                if(!visited[i]){
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
        
        return ans;
    }

};

int main() {
    int V, E;
    cin >> V >>E;

    vector<int> adj[V];

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);  
    }

    Solution obj;
    vector<int> ans = obj.bfsOfGraph(V, adj);
    
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}