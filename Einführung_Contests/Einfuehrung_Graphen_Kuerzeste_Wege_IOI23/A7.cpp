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

int n, c;
vi coins;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    test{
        cin >> n >> c;
        everyN(i){
            int coin;
            cin >> coin;
            coins.push_back(coin);
        }
        vi dp(c+1, 0);
        vvi coinSave(c+1, vi(n, 0));
        for(int i = 1; i <= c; i++){
            dp[i] = INF_INT;
            everyN(j){
                if(i - coins[j] >= 0){
                    if(dp[i] > dp[i - coins[j]]+1){
                        dp[i] = dp[i - coins[j]]+1;
                        coinSave[i] = coinSave[i - coins[j]];
                        coinSave[i][j]++;
                    }
                }
            }
        }
        cout << "Case #" << t+1 << ": ";
        for(int x : coinSave[c]){
            cout << x << " ";
        }
        coins.clear();
        cout << endl;
    }
    
    return 0;
}