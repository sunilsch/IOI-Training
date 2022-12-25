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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k, maxCount = 0, count = 0;
    cin >> n >> k;
    ve<pii> data;
    everyN(i){
        int var1, var2;
        cin >> var1 >> var2;
        data.emplace_back(var1, 1);
        data.emplace_back(var2, -1);
    }
    sort(data.begin(), data.end());
    for(pii x : data){
        count += x.second;
        maxCount = max(maxCount, count);
    }
    if(maxCount > k){
        cout << "impossible" << endl;
    } else {
        cout << "possible" << endl;
    }
    return 0;
}