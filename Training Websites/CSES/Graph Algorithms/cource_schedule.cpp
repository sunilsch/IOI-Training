#include <bits/stdc++.h>

using namespace std;

int n, m;

const int maxNodes = 100000;

vector<bool> visited(maxNodes, false);
vector<bool> finished(maxNodes, false);
vector<vector<int>> G(maxNodes);
vector<int> result;

bool possible = true;

void visit(int node){
    visited[node] = true;
    for(int newNode : G[node]){
        if(!visited[newNode]){
            visit(newNode);
        }
        if(visited[newNode] && !finished[newNode]){
            possible = false;
        }
    }
    finished[node] = true;
    result.push_back(node);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int n1, n2;
        cin >> n1 >> n2;
        n1--;n2--;
        G[n1].push_back(n2);
    }
    for(int i = 0; i < n; i++){
        if(!visited[i])
            visit(i);
    }

    if(!possible){
        cout << "IMPOSSIBLE";
    } else {
        for(int i = result.size()-1; i >= 0; i--){
            cout << result[i]+1 << " ";
        }
    }
    return 0;
}