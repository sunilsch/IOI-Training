#include <bits/stdc++.h>

using namespace std;

const int maxNodes = 100000;

vector<vector<int>> G(maxNodes);
bool possible, vis[maxNodes], group[maxNodes];
int n;

void DFS(int u, int p=0){
    for(int v : G[u]){
        if(v != p){
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
}

bool find_match(int node, vector<int>& mr, vector<int>& mc, vector<bool>& seen) {
    for (int j: G[node]) {
        if (!seen[j]) {
            seen[j] = true;
            if (mc[j] < 0 || find_match(mc[j], mr, mc, seen)) {
                mr[node] = j;
                mc[j] = node;
                cout << node << " " << j << endl;
                return true;
            }
        }
    }
    return false;
}


int max_bipartite_matching(int nBIP, int mBIP) {
    cout << endl;
    vector<int> mr;
    vector<int> mc;
    mr.assign(nBIP, -1);
    mc.assign(nBIP + mBIP, -1);
    int count = 0;
    vector<bool> seen;
    for (int i = 0; i < nBIP; i++) {
        seen.assign(mBIP, false);
        if (find_match(i, mr, mc, seen)) count++;
    }
    cout << endl;
    return count;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tins;
    cin >> tins;
    for (int t = 0; t < tins; t++){
        cin >> n;
        
        
        for(int i = 0; i < n-1; i++){
            int n1, n2;
            cin >> n1 >> n2;
            n1--;n2--;
            G[n1].push_back(n2);
            G[n2].push_back(n1);
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
        int ans = max_bipartite_matching(min(sum1,sum2), max(sum1,sum2));
        cout << ans << endl;
        cout << "Case #" << t+1 << ": " << n-ans << endl;
        for(int i = 0; i < n; i++){
            G[i].clear();
            vis[i] = false;
            group[i] = false;
        }
    }
    return 0;
}