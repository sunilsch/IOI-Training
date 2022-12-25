#include <bits/stdc++.h>

using namespace std;

const int maxNodes = 10000;

vector<vector<int>> G1(maxNodes);
vector<vector<int>> G2(maxNodes);
vector<int> punkte;
vector<bool> found(maxNodes, false);
int n, m, ans = 0;

void findNodes(){
    bool changed = false;
    for(int i = 0; i < n; i++){
        if(G2[i].empty() && !found[i]){
            ans += punkte[i];
            found[i] = true;
            changed = true;
            for(int j : G1[i]){
                G2[j].erase(remove(G2[j].begin(), G2[j].end(), i), G2[j].end());
            }
            G1[i].clear();
        }
    }
    if(changed){
        findNodes();
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tins;
    cin >> tins;
    for(int t = 0; t < tins; t++){
        cin >> n >> m;
        for(int i = 0; i < n; i++){
            int var;
            cin >> var;
            punkte.push_back(var);
        }

        for(int i = 0; i < m; i++){
            int node1, node2;
            cin >> node1 >> node2;
            node1--; node2--;
            G1[node1].push_back(node2);
            G2[node2].push_back(node1);
        }
        
        findNodes();
        
        cout << "Case #" << t+1 << ": " << ans << endl; 
        for(int i = 0; i < n; i++){
            G1[i].clear();
            G2[i].clear();
            found[i] = false;
        }
        punkte.clear();
        ans = 0;
    }

    return 0;
    
}