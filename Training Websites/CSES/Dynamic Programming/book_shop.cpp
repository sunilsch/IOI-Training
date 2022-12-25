#include <bits/stdc++.h>

#define ll long long
#define pli pair<ll, int>
#define pil pair<int, ll>
#define pii pair<int,int>
#define ve vector
#define vi ve<int>
#define vll ve<ll>
#define vvll ve<vll>
#define vvi ve<vi>
#define vvvi ve<vvi>
#define everyN(var) for(int var = 0; var < n; var++)
#define everyM(var) for(int var = 0; var < m; var++)
#define test int tins; cin >> tins; for(int t = 0; t < tins; t++)
#define INF_INT numeric_limits<int>::max()/2
#define INF_LL numeric_limits<long long>::max()/2

using namespace std;

int n, x, var;
vi prices;
vi pages;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> x;
    everyN(i){
        cin >> var;
        prices.push_back(var);
    }
    everyN(i){
        cin >> var;
        pages.push_back(var);
    }

    vvi dp(n+1, vi(x+1));
    for(int j = 0; j <= x; j++) dp[0][j] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= x; j++){
            if(prices[i-1] > j){
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-prices[i-1]] + pages[i-1]);
            }
        }
    }
    cout << dp[n][x] << endl;
    return 0;
}