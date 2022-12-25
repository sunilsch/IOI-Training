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

const int maxN = 50001;

int n, m, l, a, b, c;
int sumBefore;
int sumAfter;
ve<ve<pii>> adj(maxN);

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> l;
    everyM(i){
        cin >> a >> b >> c;
        a--; b--;
        if(i < l) sumBefore += c;
        adj[a].emplace_back(b,c);
        adj[b].emplace_back(a,c);
    }
    vi dist(n, INF_INT);
    priority_queue<pii, ve<pii>, greater<pii>> q;
    q.push({0,0});
    everyN(i){
        while(!q.empty() && q.top().first > dist[q.top().second]) q.pop();
        if(q.empty()){
            cout << "impossible" << endl;
            return 0;
        }
        int u = q.top().second;
        q.pop();
        if(i) sumAfter += dist[u];
        dist[u] = 0;
        for(auto t : adj[u]){
            if(dist[t.first] > t.second){
                dist[t.first] = t.second;
                q.push({t.second, t.first});
            }
        }
    }
    if(sumBefore >= sumAfter) cout << "possible" << endl;
    else cout << "impossible" << endl;
    return 0;
}