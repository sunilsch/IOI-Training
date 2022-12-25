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
int longestSubSequence(ve<pii> A, int n)
{
    // dp[i]: Stores the longest
    // subsequence upto i
    int dp[n];
    for (int i = 0; i < n; i++) {
 
        // Base case
        dp[i] = 1;
 
        for (int j = 0; j < i; j++) {
 
            // When the conditions hold
            if (A[j].first <= A[i].first
                && A[j].second > A[i].second) {
 
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
 
    // Finally, print the required answer
    return dp[n - 1];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    test{
        cin >> n;
        ve<pii> bauern;
        everyN(i){
            int var1, var2;
            cin >> var1 >> var2;
            bauern.emplace_back(var1, var2);
        }
        cout << "Case #" << t+1 << ": " << longestSubSequence(bauern, n) << endl;
    }
    

    
    return 0;
}