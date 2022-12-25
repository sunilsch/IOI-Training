
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

int h, n;

ve<tuple<int,int,int>> karton;

int maximumSum(){
    vi dp(n);
    int maxV = 0;
    everyN(i) dp[i] = get<2>(karton[i]);
    for(int i=1; i<n; i++) {
        for(int j=0; j<i; j++) {
            if((get<0>(karton[i]) < get<0>(karton[j])) && (get<1>(karton[i]) < get<1>(karton[j])) && (dp[i] < (dp[j]+get<2>(karton[i]))))
            {  
                dp[i] = dp[j] + get<2>(karton[i]);
            }  
        }  
    }
    everyN(i){
        maxV = max(dp[i], maxV);
    }
    return maxV;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    test{
        cin >> h >> n;
        everyN(i){
            int x, y, z;
            cin >> x >> y >> z;
            karton.push_back(make_tuple(x, y, z));
            karton.push_back(make_tuple(y, x, z));
            karton.push_back(make_tuple(x, z, y));
            karton.push_back(make_tuple(z, x, y));
            karton.push_back(make_tuple(y, z, x));
            karton.push_back(make_tuple(z, y, x));
        }
        n *= 6;
        sort(karton.begin(), karton.end());
        reverse(karton.begin(), karton.end());
        int sum = maximumSum();
        if(sum >= h){
            cout << "Case #" << t+1 << ": yes" << endl;
        } else {
            cout << "Case #" << t+1 << ": no" << endl;
        }



        karton.clear();
    }
    
    return 0;
}