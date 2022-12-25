#include <bits/stdc++.h>
using namespace std;



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    int coins[n+1];
    coins[0] = 0;
    long long dp[n];
    for(int i = 1; i <= n; i++) cin >> coins[i];
    sort(coins,coins+n+1);
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        if(dp[i-1] < coins[i]) return cout << dp[i-1], 0;
        dp[i] = dp[i-1] + coins[i];
    }
    cout << dp[n];
    return 0;
}