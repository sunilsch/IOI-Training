#include <bits/stdc++.h>

using namespace std;

// global vars

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    long long a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    long long sm = a[0], mx = a[0];
    for(int i=1; i < n; i++){
        sm = max(sm+a[i], a[i]);
        mx = max(mx,sm);
    }
    cout << mx << endl;
    return 0;
}