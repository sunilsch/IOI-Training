#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, ans = 1;
    cin >> n;
    vector<pair<long long,int>> cubes(n);
    for(int i = 0; i < n; i++) {
        cin >> cubes[i].first;
        cubes[i].second = i;
    }
    sort(cubes.begin(), cubes.end());
    for(int i = cubes.size() - 2; i >= 0; i--){
        if(cubes[i+1].second > cubes[i].second && cubes[i+1].first >= cubes[i].first) ans++;
    }
    cout << ans;
    return 0;
}