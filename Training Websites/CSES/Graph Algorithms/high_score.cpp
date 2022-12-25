#include <bits/stdc++.h>

#define ll long long
#define pli pair<ll, int>
#define pil pair<int, ll>
#define pii pair<int,int>
#define ve vector
#define vi ve<int>
#define vll ve<ll>
#define vvll ve<vll>
#define vvi ve<vi>
#define vvvi ve<vvi>
#define everyN(var) for(int var = 0; var < n; var++)
#define everyM(var) for(int var = 0; var < m; var++)
#define test int tins; cin >> tins; for(int t = 0; t < tins; t++)
#define INF_INT numeric_limits<int>::max()/2
#define INF_LL numeric_limits<long long>::max()/2

using namespace std;

const int maxNodes = 2501;

int n,m;
ve<ve<pil>> G(maxNodes);
vvi adj1(maxNodes);
vvi adj2(maxNodes);

ll bellmann(int start, vll &dist, ve<bool> vis1, ve<bool> vis2) {
    dist[start] = 0;
    everyN(i){
        everyN(v){
            for(auto p : G[v]){
                int u, w;
                tie(u, w) = p;
                if(dist[u] > dist[v]+w){
                    dist[u] = dist[v]+w;
                    if(i==(n-1) && vis1[u] && vis2[u]){
                        return 1;
                    }
                }
            }
        }
    }
    return dist[n-1];
    
}
void dfs(int node, ve<bool> &vis, vvi &adj){
    if(!vis[node]){
        vis[node] = true;
        for(auto i : adj[node]){
            dfs(i, vis, adj);
        }
    }
}
int main(){
    cin >> n >> m;
    everyM(i){
        int n1, n2;
        ll dist;
        cin >> n1 >> n2 >> dist;
        n1--; n2--;
        G[n1].emplace_back(n2, -dist);
        adj1[n1].push_back(n2);
        adj2[n2].push_back(n1);
    }

    vll dist(n, INF_LL);
    ve<bool> vis1(n);
    ve<bool> vis2(n);
    dfs(0, vis1, adj1);
    dfs(n-1, vis2, adj2);
    cout << -bellmann(0, dist, vis1, vis2) << endl;
    
}