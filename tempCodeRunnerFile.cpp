/*Write a c++  program to perform topological sort on a graph.*/

#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> adj[], int node, stack<int> &st, vector<int> &visited){
    visited[node] = 1;
    for(auto it : adj[node]){
        if(visited[it]!=1){
            dfs(adj, it, st, visited);
        }
    }
    st.push(node);
}

int main() {
    int V,E;
    cout<<"Enter No. of Vertices and edges : ";
    cin>>V>>E;
    vector<int> adj[V];
    cout << "Enter the edges (source destination):" << endl;
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    stack<int> ans;
    vector<int> visited(V, 0);
    for (int i = 0; i < V; i++)
    {
        if(!visited[i]){
            dfs(adj, i, ans, visited);
        }
    }
    cout << "Topological Sort Order: ";
    while(!ans.empty()){
        cout<<ans.top()<<" ";
        ans.pop();
    }
    return 0;
}