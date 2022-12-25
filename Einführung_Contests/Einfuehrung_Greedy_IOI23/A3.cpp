#include <bits/stdc++.h>

using namespace std;

// global vars

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    long long n, maxA=0, c;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> c;
        maxA = max(maxA, c);
    }
    cout << maxA*maxA*maxA;
    return 0;
}