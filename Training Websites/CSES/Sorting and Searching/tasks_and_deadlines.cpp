#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    long long n, a, d, duration = 0, ans = 0;
    cin >> n;
    vector<pair<long,long>> tasks;
    for(int i = 0; i < n; i++){
        cin >> a >> d;
        tasks.push_back(make_pair(a,d));
    }
    sort(tasks.begin(), tasks.end());
    
    for(pair<long,long> x : tasks){
        duration+=x.first;
        ans += x.second - duration;
    }
    cout << ans;
    return 0;
}