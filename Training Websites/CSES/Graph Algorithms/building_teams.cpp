#include <bits/stdc++.h>

#define maxN 100000

using namespace std;

int n,m;
bool possible, vis[maxN], group[maxN];
vector<int> G[maxN];

void DFS(int u, int p=0){
    for(int v : G[u]){
        if(v != p)
            if(!vis[v]){
                group[v] = !group[u];
                vis[v] = true;
                DFS(v, u);
            } else {
                if(group[v] == group[u]){
                    possible = false;
                }
            }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int node1, node2;
        cin >> node1 >> node2;
        G[node1].push_back(node2);
        G[node2].push_back(node1);
    }
    
    possible = true;
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            vis[i] = true;
            DFS(i);
        }
    }

    if(!possible){
        cout << "IMPOSSIBLE" << endl;
    } else {
        for(int i = 1; i <= n; i++){
            cout << (group[i] ? 2 : 1) << " ";
        }
    }
    return 0;
}