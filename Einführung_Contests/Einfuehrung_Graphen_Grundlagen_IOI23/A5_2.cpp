#include <bits/stdc++.h>

using namespace std;

const int maxNodes = 100000;

vector<vector<int>> G(maxNodes);

vector<bool> visited(maxNodes, false);
vector<int> punkte(maxNodes);
int n, m, ans = 0;
bool cycle;
void checkIfIsCycle(int firstNode, int node, int start){
    
    visited[node] = true;
    for(int newNode : G[node]){
        if(!visited[newNode]){
            checkIfIsCycle(firstNode, newNode, 1);
        } else {
            if(newNode == firstNode && start == 1){
                cycle = true;
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
        
        for(int i = 0; i < n; i++){
            G[i].clear();
        }
        ans = 0;
        cin >> n >> m;
        for(int i = 0; i < n; i++){
            int var;
            cin >> var;
            punkte[i] = var;
        }
        int n1last = -1, n2last = -1;
        for(int i = 0; i < m; i++){
            int n1, n2;
            cin >> n1 >> n2;
            if(n1 == n1last && n2 == n2last)
                continue;
            n1last = n1; n2last = n2;
            n1--; n2--;
            G[n1].push_back(n2);
        }

        for(int i = 0; i < n; i++){
            checkIfIsCycle(i,i,0);
            if(!cycle){
                ans+=punkte[i];
            }
            
            for(int i = 0; i < n; i++){
                visited[i] = false;
            }
            
            cycle = false;
        }
        cout << "Case #" << t+1 << ": " << ans << endl;
    }

    

    return 0;
}