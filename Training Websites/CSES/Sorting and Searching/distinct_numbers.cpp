#include <bits/stdc++.h>

using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, c, res = 1;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> c;
        arr[i] = c;
    }
    sort(arr.begin(),arr.end());
    for(int i = 1; i < n; i++){
        if(arr[i-1] != arr[i]){
            res++;
        }
    }
    cout << res;
    return 0;
}