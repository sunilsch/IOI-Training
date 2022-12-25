#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    long n;
    cin >> n;
    long sum = 0L;
    long shouldbe = (n*(n+1))/2;
    for(int i = 1; i < n; i++){
        long m;
        cin >> m;
        sum+=m;
    }
    cout << shouldbe-sum;
    
    return 0;
}