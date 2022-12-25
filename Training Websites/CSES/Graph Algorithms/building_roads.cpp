#include <bits/stdc++.h>

using namespace std;

#define MAXN 100000

int n,m;
vector<vector<int>> adj(MAXN);
vector<bool>visited(MAXN, false);
vector<int>bridges;


void DFS(int node){
    visited[node] = true;
    for (int child : adj[node]){
        if(visited[child] == false) {
            DFS(child);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int node1, node2;
        cin >> node1 >> node2;
        adj[node1].push_back(node2);
        adj[node2].push_back(node1);
    }
    for(int i = 1; i <= n; i++){
        if(visited[i] == false){
            bridges.push_back(i);
            DFS(i);
        }
    }
    cout << bridges.size() - 1 << endl;
    for(int i = 0; i < bridges.size() -1 ; i++){
        cout << bridges[i] << " " << bridges[i + 1] << endl;
    } 
    
    return 0;
}