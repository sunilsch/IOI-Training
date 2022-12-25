#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> schools(1001);

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tins;
    cin >> tins;
    for(int t = 0; t < tins; t++){
        int n;
        cin >> n;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 5; j++){
                int var;
                cin >> var;
                schools[i].push_back(var);
            }
            sort(schools[i].begin(), schools[i].end());
            reverse(schools[i].begin(), schools[i].end());
        }
        sort(schools.begin(), schools.end());
        reverse(schools.begin(), schools.end());
        cout << "Case #" << t+1 << ":" << endl;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 5; j++){
                cout << schools[i][j] << " ";
            }
            cout << endl;
        }
        for(int i = 0; i < n; i++){
            schools[i].clear();
        }
    }
    
    
    return 0;
}