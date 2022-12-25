#include <bits/stdc++.h>

using namespace std;

const int maxNodes = 100000;
int n,m,maxDepth=0,bestNode,minMaxDepth=99999999;

vector<bool> visited(maxNodes, false);
vector<vector<int>> G(maxNodes);


void visit(int node, int depth){
    if(depth > minMaxDepth){
        return;
    }
    visited[node] = true;
    for(int newNode : G[node]){
        if(!visited[newNode])
            visit(newNode,depth+1);
    }
    if(depth > maxDepth){
        maxDepth = depth;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tIns;
    cin >> tIns;
    for(int t = 0; t < tIns; t++){

        cin >> n;

        for(int i = 0; i < n; i++){
            G[i].clear();
        }
        minMaxDepth=99999999;
        for(int i = 0; i < n-1; i++){
            int n1, n2;
            cin >> n1 >> n2;
            G[n1].push_back(n2);
            G[n2].push_back(n1);
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                visited[j] = false;
            }
            visit(i, 0);
            if(maxDepth < minMaxDepth){
                minMaxDepth = maxDepth;
                bestNode = i;
            }
            maxDepth = 0;
        
        }
        cout << "Case #" << t+1 << ": " << bestNode << endl;
    }
    return 0;
}