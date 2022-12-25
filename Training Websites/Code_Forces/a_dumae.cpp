#include <bits/stdc++.h>

using namespace std;

int n, m;

const int maxNodes = 100000;

vector<bool> visited(maxNodes, false);
vector<bool> finished(maxNodes, false);
vector<vector<int>> G(maxNodes);
vector<pair<int, int>> range;
vector<int> result;

bool possible = true;

void visit(int node){
    visited[node] = true;
    for(int newNode : G[node]){
        if(!visited[newNode]){
            visit(newNode);
        }
        if(visited[newNode] && !finished[newNode]){
            possible = false;
        }
    }
    finished[node] = true;
    result.push_back(node);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int r1, r2;
        cin >> r1 >> r2;
        range.push_back(make_pair(r1,r2));
    }
    for(int i = 0; i < m; i++){
        int n1, n2;
        cin >> n1 >> n2;
        n1--;n2--;
        G[n1].push_back(n2);
    }
    for(int i = 0; i < n; i++){
        if(!visited[i])
            visit(i);
    }

    if(!possible){
        cout << -1;
    } else {
        sort(result.begin(), result.end());
        /*for(int r : result)
            cout << r << endl;
        for(int i = 0; i < n; i++)
            cout << range[i].first << range[i].second;*/
        for(int i = 0; i < result.size(); i++){
            if((i+1) < range[i].first || (i+1) > range[i].second){
                cout << -1;
                return 0;
            }
        }
        for(int r : result)
            cout << r+1 << endl;
    }
    return 0;
}