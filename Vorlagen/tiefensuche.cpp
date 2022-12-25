#include <bits/stdc++.h>

using namespace std;

const int maxNodes = 100000;
int n,m;

vector<bool> visited(maxNodes, false);
vector<vector<int>> G(maxNodes);


void visit(int node){
    visited[node] = true;
    cout << node << endl;
    for(int newNode : G[node]){
        if(!visited[newNode])
            visit(newNode);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n; //nodes
    cin >> m; //edges
    for(int i = 0; i < m; i++){
        int n1, n2;
        cin >> n1 >> n2;
        G[n1].push_back(n2);
        G[n2].push_back(n1);
    }

    for(int i = 0; i < n; i++)
        if(!visited[i])
            visit(i);
    
    return 0;
}