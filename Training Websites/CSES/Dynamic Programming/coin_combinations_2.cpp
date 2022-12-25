#include <bits/stdc++.h>

using namespace std;



long long dp[1000001];
const int MOD = (int) 1e9 + 7;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,x;
    
    cin >> n >> x;
    
    vector<int> coins(n);
    
    for (int i = 0; i < n; i++) {
		cin >> coins[i];
	}
    
    dp[0] = 1;
    
    for(int i = 1; i <= n; i++){
        for(int weight = 0; weight <= x; weight++){
            if(weight - coins[i - 1] >= 0){
                dp[weight] += dp[weight - coins[i - 1]];
                dp[weight] %= MOD;
                
            }
        }
    }
    cout << dp[x];
    
    return 0;
}