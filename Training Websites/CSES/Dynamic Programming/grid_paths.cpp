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

const ll MOD = 1e9+7;
const int maxN = 1000;
char grid[maxN+1][maxN+1];
ll dp[maxN+1][maxN+1];

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> grid[i][j];
    dp[1][1] = (grid[1][1] == '.');
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(grid[i][j] == '.'){
                if(grid[i-1][j] == '.')    dp[i][j] += dp[i-1][j];
                if(grid[i][j-1] == '.')    dp[i][j] += dp[i][j-1];
                dp[i][j] %= MOD;
            }
        }
    }
    cout << dp[n][n] << endl;
    
    return 0;
}