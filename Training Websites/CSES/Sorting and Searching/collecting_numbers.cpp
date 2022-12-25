#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,c,ans = 1;
    cin >> n;
    int index_arr[n+1];
    index_arr[0] = 0;
    for(int i = 0; i < n; i++){
        cin >> c;
        index_arr[c] = i;
    }
    for(int i = 1; i < n+1; i++) if(index_arr[i] < index_arr[i-1]) ans++;
    cout << ans;
    return 0;
}