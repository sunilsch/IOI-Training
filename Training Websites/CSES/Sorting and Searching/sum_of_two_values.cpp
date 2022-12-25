#include <bits/stdc++.h>

using namespace std;

// global vars

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,x;
    cin >> n >> x;

    vector<int> values(n);

    map<int,int> map_values;
    for(int i = 0; i < n; i++) cin >> values[i];
    for(int i = 0; i < n; i++){
        if(map_values.count(x - values[i])){
            cout << i +1 << " " << map_values[x - values[i]] << endl;
            return 0;
        }
        map_values[values[i]] = i + 1;
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}