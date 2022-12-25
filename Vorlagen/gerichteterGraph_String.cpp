#include <bits/stdc++.h>

using namespace std;

const int maxNodes = 100000;

vector<vector<int>> G(maxNodes);
map<string,int> names;
int a = 0, n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++){
        string name1, name2;
        char op;
        cin >> name1 >> op >> name2;
        if(!names.count(name1)){
            names[name1] = a;
            a++;
        }
        if(!names.count(name2)){
            names[name2] = a;
            a++;
        }
        if(op == '>'){
            G[names[name1]].push_back(names[name2]);
        } else {
            G[names[name2]].push_back(names[name1]);
        }
    }
    return 0;
}