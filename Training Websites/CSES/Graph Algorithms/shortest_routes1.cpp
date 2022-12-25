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

const int maxNodes = 10e5;

ve<ve<pil>> G(maxNodes);
int n,m;

void dijkstra(int start, vll &dist){
    priority_queue<pli, ve<pli>, greater<pli>> q;
    q.push({0, start});
    while(!q.empty()){
        ll d;
        int v;
        tie(d, v) = q.top();
        q.pop();
        if(dist[v] <= d) continue;
        dist[v] = d;
        for(auto p : G[v])
            q.push({p.second + d, p.first});
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
    vll dist(n, INF_LL);
    dijkstra(0, dist);
    everyN(i){
        cout << dist[i] << " ";
    }
    return 0;
}