#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 2e5;

int n,m,k,c, desired_sizes[MAX_N], sizes[MAX_N], ans;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) cin >> desired_sizes[i];
    for(int i = 0; i < m; i++) cin >> sizes[i];
    sort(desired_sizes, desired_sizes + n);
    sort(sizes, sizes + m);
    int i = 0, j = 0;
    while(i < n && j < m){
        if(abs(desired_sizes[i] - sizes[j]) <= k){
            i++; j++; ans++;
        } else {
            if(desired_sizes[i] - sizes[j] > k){
                j++;
            } else {
                i++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}