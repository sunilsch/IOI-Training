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

int n;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    int dp[n+1];
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        set<int> s;
        for(auto j : to_string(i)){
            s.insert(j-'0');
        }
        dp[i] = INF_INT;
        for(int j : s){
            dp[i] = min(dp[i], dp[i-j]+1);
        }
    }
    cout << dp[n] << endl;
    
    return 0;
}