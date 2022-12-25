#include <bits/stdc++.h>

using namespace std;

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


const int maxNodes = 100000;

ve<ve<pil>> G(maxNodes);
int n, m;

void dijkstra(int start, ve<ll> &dist) {

    priority_queue<pli, ve<pli>, greater<pli> > q;

    q.push({0, start});
    while (q.size()) {
        ll d;
        int v;
        tie(d, v) = q.top();
        q.pop();
        if (dist[v] <= d) continue;
        dist[v] = d;
        for (auto p: G[v]) {
            q.push({d + p.second, p.first});
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tins;
    cin >> tins;

    for(int t = 0; t < tins; t++){
        cin >> n >> m;
        everyM(i){
            int n1, n2;
            ll distA;
            cin >> n1 >> n2 >> distA;
            n1--; n2--;
            G[n1].push_back(make_pair(n2, distA));
            G[n2].push_back(make_pair(n1, distA));
        }
        ll ans = 0;
        everyN(i){
            vll dist(n, INF_LL);
            dijkstra(i, dist);
            for(int x : dist){
                ans += x*2;
            }

        }
        cout << "Case #" << t+1 << ": " << ans << endl;
        everyN(i){
            G[i].clear();
        }
    }
    return 0;
}