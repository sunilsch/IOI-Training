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

map<int,double> ma;
int n;
double ans;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ma[0] = 2.0;
    ma[1] = 1.0;
    ma[2] = 1.0/2.0;
    ma[4] = 1.0/4.0;
    ma[8] = 1.0/8.0;
    ma[16] = 1.0/16.0;

    cin >> n;
    ans = 0.0;
    everyN(i){
        int m;
        cin >> m;
        ans += ma[m];
    }
    cout << ans << endl;
    return 0;
}