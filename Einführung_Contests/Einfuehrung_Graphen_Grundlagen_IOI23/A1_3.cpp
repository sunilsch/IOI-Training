#include <bits/stdc++.h>

using namespace std;

const int maxNodes = 100000;

vector<vector<int>> G(maxNodes);
vector<int> msize(maxNodes);
int n;


int MIST(int v, int p){
    int skip = 0;
    for(int node : G[v]){
        if(node != p)
            skip+=MIST(node, v);
    }
    int keep = 1;
    for(int node : G[v]){
        if(node != p){
            for(int secondNode : G[node]){
                if(secondNode != node){
                    keep += msize[secondNode];
                }
            }
        }
    }
    msize[v] = max(skip, keep);
    return msize[v];
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
            n1--;n2--;
            G[n1].push_back(n2);
            G[n2].push_back(n1);
        }
        cout << "Case #" << t+1 << ": " << MIST(0, -1) << endl;
        for(int i = 0; i < n; i++){
            G[i].clear();
            msize[i] = 0;
        }
    }
    
    return 0;
}