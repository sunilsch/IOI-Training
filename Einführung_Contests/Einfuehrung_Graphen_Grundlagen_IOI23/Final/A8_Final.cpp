#include <bits/stdc++.h>

using namespace std;

const int maxNodes = 100000;

vector<vector<pair<int,long long>>> G(maxNodes);
vector<long long> dist(maxNodes, 1e18);
vector<int> stationen;

int n, m, s;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tins;
    cin >> tins;
    for(int t = 0; t < tins; t++){
        cin >> n >> m >> s;
        for(int i = 0; i < m; i++){
            int n1, n2;
            long long dist;
            cin >> n1 >> n2 >> dist;
            n1--; n2--;
            G[n1].emplace_back(n2, dist);
            G[n2].emplace_back(n1, dist);
        }
        for(int i = 0; i < s; i++){
            int station;
            cin >> station;
            station--;
            stationen.push_back(station);
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
        q.push({0, 0});
        while(!q.empty()){
            long long d;
            int v;
            tie(d, v) = q.top();
            q.pop();
            if(dist[v] <= d) continue;
            dist[v] = d;
            for(pair<int, long long> x : G[v]){
                q.push({d+x.second, x.first});
            }
        }
        int min = 1e9;
        for(int x : stationen){
            if(dist[x] <= min){
                min = dist[x];
            }
        }
        vector<int> a;
        cout << "Case #" << t+1 << ": " << min;
        for(int x : stationen){
            if(min == dist[x]){
                a.push_back(x+1);
            }
        }
        sort(a.begin(), a.end());
        for(int x : a) cout << " " << x;
        cout << endl;
        for(int i = 0; i < n; i++){
            G[i].clear();
            dist[i] = 1e18;
        }
        stationen.clear();
    }

    return 0;
}