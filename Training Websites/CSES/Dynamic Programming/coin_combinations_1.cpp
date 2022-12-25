#include <bits/stdc++.h>

#define MAXN 1000001
#define MOD 1000000007

using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,x,c;
    cin >> n >> x;
    vector<int> coins;

    for(int i = 0; i < n; i++){
        cin >> c;
        coins.push_back(c);
    }

    vector<int> dp(x+1,0);
    dp[0] = 1;

    for(int i = 1; i<=x;i++){
        for(int j = 0; j < n; j++){
            if(i-coins[j] >= 0){
                dp[i] += dp[i-coins[j]];
            }
            dp[i] %= MOD;
            
        }
    }

    cout << dp[x] << endl;
    
    return 0;
}