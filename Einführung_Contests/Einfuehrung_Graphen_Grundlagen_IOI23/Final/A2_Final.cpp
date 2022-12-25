#include <bits/stdc++.h>

using namespace std;

const int maxNodes = 100000;

vector<vector<int>> G(maxNodes);
vector<int> schoenheit;
vector<int> nKatzen;


int n, ans;

void visit(int node){
    ans += nKatzen[node];
    int maxVal = schoenheit[node], index;
    for(int newNode : G[node]){
        if(maxVal < schoenheit[newNode]){
            maxVal = schoenheit[newNode];
            index = newNode;
        }
        
    }
    if(!(maxVal == schoenheit[node])){
        visit(index);
    }
    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    int val;
    for(int i = 0; i < n; i++){
        cin >> val;
        schoenheit.push_back(val);
    }
    for(int i = 0; i < n; i++){
        cin >> val;
        nKatzen.push_back(val);
    }
    for(int i = 0; i < n; i++){
        int m;
        cin >> m;
        for(int j = 0; j < m; j++){
            cin >> val;
            val--;
            G[i].push_back(val);
        }
    }
    visit(0);
    cout << ans << endl;

    return 0;
}