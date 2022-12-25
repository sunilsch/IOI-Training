#include <bits/stdc++.h>

using namespace std;

long long n, m;

vector<int> liste;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int val;
        cin >> val;
        liste.push_back(val);
    }
    sort(liste.begin(), liste.end());
    for(int i = 0; i < m; i++){
        int val, k;
        cin >> val >> k;
        cout << val-liste[k-1] << endl;
    }
    
    return 0;
}