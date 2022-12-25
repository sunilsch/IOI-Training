#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    long long ans = 0;
    cin >> n;
    vector<int> sticks(n);
    for(int i = 0; i < n; i++) cin >> sticks[i];
    sort(sticks.begin(), sticks.end());
    int mid = sticks[n/2];
    for(int i = 0; i < n; i++)
        ans+=(long long)abs(sticks[i]-mid);
    cout << ans << endl;
    return 0;
}