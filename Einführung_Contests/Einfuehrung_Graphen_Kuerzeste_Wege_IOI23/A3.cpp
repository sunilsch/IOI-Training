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

int n, ans = 0;

/*void dfs(int node, vvi &G, vi &res){
    everyN(i){
        if(G[i][node] > 0){
            res[i] = max(res[i], G[i][node]);
            G[i][node] = 0;
            dfs(i, G, res);
        }
    }
}*/

void dfs2(int node, vvi &G, ve<bool> &visited){
    visited[node] = true;
    everyN(i){
        if(!visited[i] && G[i][node] > 0){
            dfs2(i, G, visited);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    test{
        cin >> n;
        vvi G(n, vi(n));
        //vi res(n, 0);
        ve<bool> visited(n, false);
        int ans = 0;
        everyN(i){
            everyN(j){
                int val;
                cin >> val;
                G[i][j] = val;
            }
        }
        dfs2(0, G, visited);
        for(int i = 1; i < n; i++){
            if(visited[i]){
                int a = 0;
                for(int j = 0; j < n; j++){
                    if(visited[j]){
                        a = max(a, G[i][j]);    
                    }
                    
                }
                ans += a;
            }
        }
        cout << "Case #" << t+1 << ": " << ans << endl;
        ans = 0;
        
    }
    
    return 0;
}