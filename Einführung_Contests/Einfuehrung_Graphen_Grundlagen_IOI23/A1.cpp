#include <bits/stdc++.h>

#define maxN 100000

using namespace std;

int m,n;
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

    cin >> m;
    for(int t = 0; t < m; t++){
        cin >> n;

        for(int i = 0; i < n; i++){
            G[i].clear();
            vis[i] = false;
            group[i] = false;
        }

        for(int i = 0; i < n-1; i++){
            int node1, node2;
            cin >> node1 >> node2;
            node1--;node2--;
            G[node1].push_back(node2);
            G[node2].push_back(node1);
        }
        
        possible = true;
        DFS(0);
        int sum1 = 0, sum2 = 0;
        for(int i = 0; i < n; i++){
            if(group[i]){
                sum1++;
            } else {
                sum2++;
            }
        }
        cout << "Case #" << t+1 << ": " << max(sum1, sum2) << " " << sum1 << " " << sum2 << endl;
        

    }
    return 0;
}