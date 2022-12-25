#include <bits/stdc++.h>

using namespace std;



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, used = 0;
    double ans = 0.0;
    cin >> n >> m;
    vector<pair<double,int>> buffet(n);
    
    for(int i = 0; i < n; i++){
        string name;
        cin >> name >> buffet[i].second >> buffet[i].first;
    }
    sort(buffet.begin(), buffet.end());
    for(int i = n - 1; i >= 0; i--){
        if(used+buffet[i].second <= m){
            used += buffet[i].second;
            ans += (double)buffet[i].second * buffet[i].first;
        } else {
            ans += (double)(m-used) * buffet[i].first;
            used = m;
        }
        if(used >= m){
            break;
        }
    }
    cout << ans;
    return 0;
}