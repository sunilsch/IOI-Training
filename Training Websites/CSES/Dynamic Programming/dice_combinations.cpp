#include <bits/stdc++.h>

#define MAXN 1000001
#define MOD 1000000007

using namespace std;

int DP[MAXN], n;

int compute(int left) {
    if (DP[left] != 0){
        return DP[left];
    }
    for(int i = 1; i <= 6; i++){
        if (left - i >= 0){
            DP[left] += compute(left - i);
            DP[left] %= MOD;
        }
    }
    return DP[left];
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    memset(DP, 0, sizeof(DP));
    DP[0] = 1;

    cout << compute(n) << endl;
    
    return 0;
}