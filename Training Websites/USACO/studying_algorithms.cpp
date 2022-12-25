#include <bits/stdc++.h>

using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, x, sum = 0, ans = 0;
    cin >> n >> x;
    int arr[n];
    for(int i = 0; i < n;i++) cin >> arr[i];
    sort(arr, arr+n);

    for(;ans < n && sum + arr[ans] <= x;ans++) sum += arr[ans];

    cout << ans;
    return 0;
}