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

void floyd(vvll &dist) {
    everyN(i){
        for(auto x : G[i]){
            dist[i][x.first] = x.second;
        }
    }
    everyN(k)
        everyN(i)
            everyN(j)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}

int main(){
    cin >> n >> m;
    everyM(i){
        int n1, n2;
        ll dist;
        cin >> n1 >> n2 >> dist;
        G[n1].emplace_back(n2, dist);
        G[n2].emplace_back(n1, dist);
    }

    vvll dist(n, vll(n, INF_LL));
    floyd(dist);
    cout << dist[0][1] << endl;
}