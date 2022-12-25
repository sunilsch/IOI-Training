#include <bits/stdc++.h>

#define ll long long
#define pli pair<ll, int>
#define pil pair<int, ll>
#define pll pair<ll,ll>
#define ppli pair<pll, int>
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

const int maxNodes = 100000;
int n,m;
ve<ve<pil>> G(maxNodes);

void dijkstra(int start, ve<pll> &dist) {

    priority_queue<ppli, ve<ppli>, greater<ppli> > q;
    q.push({{0, 0}, start});
    while (q.size()) {
        pair<ll,ll> dPair;
        ll d, maxDist;
        int v;
        tie(dPair, v) = q.top();
        tie(d, maxDist) = dPair;
        q.pop();
        if (dist[v].first-dist[v].second+(dist[v].second/2) <= d-maxDist+(maxDist/2)) continue;
        dist[v] = {d, maxDist};
        for (auto p: G[v]) {
            q.push({{d + p.second, max(p.second, maxDist)}, p.first});
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    everyM(i){
        int n1, n2;
        long long dist;
        cin >> n1 >> n2 >> dist;
        n1--; n2--;
        G[n1].emplace_back(n2, dist);
    }
    ve<pll> dist(n, make_pair(INF_LL,0));
    dijkstra(0, dist);
    cout << dist[n-1].first-dist[n-1].second+(dist[n-1].second/2) << endl;
    return 0;
}