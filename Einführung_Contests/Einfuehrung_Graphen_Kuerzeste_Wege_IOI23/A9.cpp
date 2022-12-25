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

int n, k;
vi arr;

int calcMaxSubSeqSum(){
   vi maxSumDP(n);
   maxSumDP[n - 1] = arr[n - 1];
   for (int i = n - 2; i >= 0; i--) {
      if (i + k + 1 >= n)
         maxSumDP[i] = max(arr[i], maxSumDP[i + 1]);
      else
         maxSumDP[i] = max(arr[i] + maxSumDP[i + k + 1], maxSumDP[i + 1]);
   }
   return maxSumDP[0];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    everyN(i){
        int var;
        cin >> var;
        arr.push_back(var);
    }
    if(n < 2 || k >= n){
        cout << 0 << endl;
        return 0;
    }
    arr.erase(arr.begin(), arr.begin() + k);
    n -= k;
    k--;
    cout << calcMaxSubSeqSum() << endl;
    return 0;
}
