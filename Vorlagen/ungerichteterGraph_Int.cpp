#include <bits/stdc++.h>

using namespace std;

const int maxNodes = 100000;

vector<vector<int>> G(maxNodes);
int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++){
        int n1, n2;
        cin >> n1 >> n2;
        G[n1].push_back(n2);
        G[n2].push_back(n1);
    }
    return 0;
}