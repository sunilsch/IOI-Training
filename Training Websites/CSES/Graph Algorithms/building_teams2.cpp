#include <bits/stdc++.h>

using namespace std;

vector<int> G[100001];
vector<int> dist(100001, -1);


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int n1, n2;
        cin >> n1 >> n2;
        G[n1].push_back(n2);
        G[n2].push_back(n1);
    }
    
    queue<int> q;
    for(int i = 0; i < n; i++){
        if(dist[i] == -1){
            q.push(i);
            dist[i] = 0;
            while(!q.empty()){
                int node = q.front();
                q.pop();
                for(int j = 0; j < G[node].size(); j++){
                    int nextNode = G[node][j];
                    int nextDistance = dist[node] + 1;
                    if(dist[nextNode] == -1){
                        dist[nextNode] = nextDistance;
                        q.push(nextNode);
                    } else {
                        if((dist[nextNode] % 2) != (nextDistance % 2)){
                            cout << "IMPOSSIBLE";
                            return 0;
                        }
                    }
                }
            }
        }
        
    }
    
    for(int i = 1; i <= n; i++){
        //cout << dist[i] << endl;
        cout << 1+(dist[i] % 2) << " "; 
    }
    return 0;
}