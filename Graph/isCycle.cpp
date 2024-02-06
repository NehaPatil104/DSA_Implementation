#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    bool isCycleBFS(int src, vector<int> adj[], unordered_map<int, bool> &visited){
        unordered_map<int, int> parent;
        queue<int> q;
        
        parent[src] = -1;
        q.push(src);
        visited[src] = true;
        
        while(!q.empty()){
            int front = q.front();
            q.pop();
            
            for(auto i : adj[front]){
                if(visited[i] && i != parent[front]){
                    return true;
                }
                else if(!visited[i]){
                    q.push(i);
                    visited[i] = true;
                    parent[i] = front;
                }
            }
        }
        
        return false;
    }

    bool cycleDetectDFS(int node, int parent, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj){

    visited[node] = true;

    for(auto neighbour : adj[node]){
        if(!visited[neighbour]){
            bool isCycle = cycleDetectDFS(neighbour, node, visited, adj);
            if(isCycle)
                return true;
        }
        else if(neighbour != parent){
            return true;
        }
    }

    return false;
}

    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        
        unordered_map<int, bool> visited;
        
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                bool ans = isCycleBFS(i, adj, visited);
                
                if(ans)
                    return true;
            }
        }
        
        return false;
    }
};

int main() {

    int V, E;
    cin >> V >> E;
    vector<int> adj[V];
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    Solution obj;
    bool ans = obj.isCycle(V, adj);

    if (ans)
        cout << "1\n";
    else
        cout << "0\n";

    return 0;
}