#include <bits/stdc++.h>

#define MAXN 100000

using namespace std;

int n,m;
vector<vector<int>> network(MAXN);
vector<bool>visited(MAXN, false);
vector<int>previousStep(MAXN);
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int node1, node2;
        cin >> node1 >> node2;
        network[node1].push_back(node2);
        network[node2].push_back(node1);
    }

    queue<int> q;

    q.push(1);
    visited[1] = true;

    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v:network[u]){
            if(visited[v]) continue;
            visited[v] = true;
            previousStep[v] = u;
            q.push(v);
        }
    }
    int end = n;
    if(visited[end]){
        vector<int> steps;
        while (end != 1){
            int p = previousStep[end];
            steps.push_back(p);
            end = p;
        }
        reverse(steps.begin(),steps.end());
        steps.push_back(n);

        cout << steps.size() << endl;
        for(int step : steps){
            cout << step << " ";
        }
    } else {
        cout << "IMPOSSIBLE";
    }

    return 0;
}