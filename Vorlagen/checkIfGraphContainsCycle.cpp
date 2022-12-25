#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph(100000);
vector<bool> visited;
vector<bool> finished;
int n, m;
bool possible = true;
void visit(int v){
    visited[v] = true;
    for(int i : graph[v]){
        if(!visited[i]){
            visit(i);
        }
        if(visited[i] && !finished[i]){
            possible = false;
            return;
        }
    }
    finished[v] = true;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int node1, node2;
        cin >> node1 >> node2;
        node1--;node2--;
        graph[node1].push_back(node2);
    }
    for(int i = 0; i < n; i++){
        visited.push_back(false);
        finished.push_back(false);
    }

    for(int i = 0; i < n; i++){
        if(!visited[i]){
            visit(i);
        }
    }
    cout << (possible ? "no cycle" : "cycle");
    return 0;
}