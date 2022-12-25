#include <bits/stdc++.h>

using namespace std;

const int maxNodes = 100000;

vector<vector<int>> G(maxNodes);
int n;

int breitensuche(int start){
    vector<bool> visited(maxNodes, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    int node;
    while(!q.empty()){
        node = q.front();
        q.pop();
        for (int nextNode : G[node]){
            if(!visited[nextNode]){
                q.push(nextNode);
                visited[nextNode] = true;
            }
        }
        
    }
    return node;
}
bool getDiameterPath(int res1, int res2, int parent, vector<int>& path)
{
    if (res1 == res2) {
        path.push_back(res1);
        return true;
    }
    for (auto i : G[res1]) {
        if (i == parent)
            continue;
        if (getDiameterPath(i, res2, res1, path)) {
            path.push_back(res1);
            return true;
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tins;
    cin >> tins;
    for (int t = 0; t < tins; t++){
        cin >> n;
        for(int i = 0; i < n-1; i++){
            int n1, n2;
            cin >> n1 >> n2;

            G[n1].push_back(n2);
            G[n2].push_back(n1);
        }

        int res1 = breitensuche(0);
        int res2 = breitensuche(res1);

        vector<int> path;
        getDiameterPath(res1, res2, -1, path);
        cout << "Case #" << t+1 << ": " << path[path.size() / 2] << endl;
        for(int i = 0; i < n; i++){
            G[i].clear();
        }
    }
    return 0;
}