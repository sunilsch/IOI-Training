#include <bits/stdc++.h>

using namespace std;

const int maxNodes = 100000;

vector<vector<int>> G(maxNodes);
int n, m;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int n1, n2;
        cin >> n1 >> n2;
        n1--; n2--;
        G[n1].push_back(n2);
    }


    return 0;
}