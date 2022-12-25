#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    long long last;
    cin >> last;
    long long sum = 0L;
    for(int i = 1; i < n; i++){
        long long x;
        cin >> x;
        if(last >= x)sum+=(last-x);
        else last = x;
    }
    cout << sum;
    return 0;
}