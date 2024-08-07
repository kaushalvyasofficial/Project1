/*Represent a given graph using adjacency list representation to perform BFS traversal on graph.
enter no. of edges and vertices: 6
7
enter the edges: 0 1
0 2
1 3
1 4
2 4
3 5
4 5
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(vector<int> adj[], int V, int node){
    vector<int> visited(V, 0);
    vector<int> ans;
    queue<int> q;
    q.push(node);
    visited[node] = 1;
    while(!q.empty()){
        int curr = q.front();
        ans.push_back(curr);
        q.pop();
        for(auto i : adj[curr]){
            if(visited[i]!=1){
                q.push(i);
                visited[i] = 1;
            }
        }
    }
    return ans;
}

int main() {
    int V, E;
    cout<<"enter no. of edges and vertices: ";
    cin>>V>>E;
    vector<int> adj[V];
    cout<<"enter the edges: ";
    for(int i = 0; i<E; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int node = 0;
    vector<int> ans = bfs(adj, V, node);
    cout<<"BFS traversal : ";
    for(auto i : ans){
        cout<<i<<" ";
    }
    return 0;
}