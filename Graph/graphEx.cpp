#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>

using namespace std;

class Graph{
    public:

        unordered_map<int, list<int>> adj;

        void addEdge(int u, int v, bool direction){

            adj[u].push_back(v);

            if(direction == 0)
                adj[v].push_back(u);

        }

        void printAdjList(){

            for(auto i : adj){
                cout<<i.first<<" -> ";
                for(auto j : i.second){
                    cout<<j<<", ";
                }
                cout<<endl;
            }
        }

        void bfs(){
            unordered_map<int, bool> visited;
            queue<int> q;

            q.push(0);
            visited[0] = true;

            while(!q.empty()){
                // Get the node from queue
                int frontNode = q.front();

                // Pop front node
                q.pop();

                // Print the node
                cout<<frontNode<<" ";

                // Add neighbours to queue
                for(auto i : adj[frontNode]){
                    // If neighbour not visited add it to queue
                    if(!visited[i]){
                        q.push(i);
                        // Mark neighbour visited as true
                        visited[i] = true;
                    }
                }
            }

        }

        void dfs(vector<int> &visited, int node){
            cout<<node<<" ";
            visited[node] = 1;

            for(auto i : adj[node]){
                if(visited[i] == 0)
                    dfs(visited, i);
            }
        }

};

int main(){
    
    Graph g;

    int n;
    cout<<"\nEnter number of nodes: ";
    cin>>n;

    int m;
    cout<<"\nEnter number of edges: ";
    cin>>m;

    int u, v;
    cout<<"\nEnter edges: "<<endl;
    for(int i = 0; i < m; i++){
        cin>>u>>v;
        g.addEdge(u, v, 0);
    }

    cout<<"\nAdjacency List -> "<<endl;
    g.printAdjList();

    cout<<"\nBFS -> ";
    g.bfs();

    vector<int> visited(n, 0);
    cout<<"\nDFS -> ";
    g.dfs(visited, 0);

    
    return 0;
}