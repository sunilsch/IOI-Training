#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pli pair<long long, int>
#define pil pair<int, long long>
#define ve vector
#define everyN(var) for(int var = 0; var < n; i++)
#define everyM(var) for(int var = 0; var < m; i++)
#define test int tins; cin >> tins; for(int t = 0; t < tins; t++)

const ll INF = numeric_limits<ll>::max() / 2;
const int maxNodes = 10001;

ve<ve<pil>> G(maxNodes);
int n,m;
ll ans = 0;


void dijkstra(int start, vector<ll> &dist) {
    priority_queue<pli, vector<pli>, greater<pli> > q;

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
    
    test{
        cin >> n >> m;
        everyM(i){
            int n1, n2;
            ll dist;
            cin >> n1 >> n2 >> dist;
            G[n1].emplace_back(n2, dist);
            G[n2].emplace_back(n1, dist);
        }
        vector<ll> dist1(n, INF);
        vector<ll> dist2(n, INF);
        dijkstra(0, dist1);
        dijkstra(n-1, dist2);
        everyN(i){
            for(pil y : G[i]){
                int n1 = i, n2;
                ll weight;
                tie(n2, weight) = y;
                if(dist1[n1] + weight + dist2[n2] == dist1[n-1])
                    ans += weight;
            }
        }
        cout << "Case #" << t+1 << ": " << ans*2 << endl;
        everyN(i){
            G[i].clear();
        }
        ans = 0;
    }
    return 0;
}