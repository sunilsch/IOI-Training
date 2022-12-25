#include <bits/stdc++.h>

using namespace std;

// global vars

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    long long c,n,x;
    vector<long long> coins;

    cin >> n >> x;

    for(int i = 0; i < n; i++){
        cin>>c;
        coins.push_back(c);
    }
    
    vector<long long> dp(x+1,0);
    
    for(long long i = 1; i<=x;i++){
        dp[i] = INT_MAX;
        for(long long j = 0; j < n; j++){
            if(i-coins[j] >= 0){
                dp[i] = min(dp[i], dp[i - coins[j]]+1);
            }
        }
    }

    cout << (dp[x] >= INT_MAX ? -1 : dp[x]) << endl;

    return 0;
}