#include <bits/stdc++.h>

using namespace std;

const int maxNodes = 10001;

vector<vector<pair<int,long long>>> G(maxNodes);
vector<long long> dist(maxNodes, 1e18);
vector<vector<int>> preV(maxNodes);
vector<int> visited(maxNodes, false);
long long weights[maxNodes][maxNodes];
int n, m;
long long ans = 0LL;

void calculate(int node){
    if(!visited[node]){
        for(int x : preV[node]){
            if(x != -1){
                ans += weights[node][x]*2;
                calculate(x);
                visited[node] = true;
            }
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
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) weights[i][j] = -1;
        for(int i = 0; i < m; i++){
            int n1, n2;
            long long dist;
            cin >> n1 >> n2 >> dist;
            G[n1].emplace_back(n2, dist);
            G[n2].emplace_back(n1, dist);
            weights[n1][n2] = ((weights[n1][n2] == -1) ? dist : min(weights[n1][n2], dist));
            weights[n2][n1] = ((weights[n2][n1] == -1) ? dist : min(weights[n2][n1], dist));
        }
        priority_queue<pair<long long, pair<int,int>>, vector<pair<long long, pair<int,int>>>, greater<pair<long long, pair<int,int>>>> q;
        q.push({0, {0,-1}});
        while(!q.empty()){
            long long d;
            pair<int,int> V;
            int v;
            int last;
            tie(d, V) = q.top();
            tie(v, last) = V;
            q.pop();
            if(dist[v] < d) continue;
            preV[v].push_back(last);
            if(dist[v] == d) continue;
            dist[v] = d;
            for(pair<int, long long> x : G[v]){
                q.push({d+x.second, {x.first,v}});
            }
        }
        
        calculate(n-1);
        cout << "Case #" << t+1 << ": " << ans << endl;
        for(int i = 0; i < n; i++){
            G[i].clear();
            preV[i].clear();
            dist[i] = 1e18;
            visited[i] = false;
        }
        ans = 0;
    }

    return 0;
}