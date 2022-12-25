#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    int arr [n];
    for(int i = 0; i < n; i++) arr[i]=0;
    for(int i = 0; i < m*2; i++){
        int j;
        cin >> j;
        arr[j]++;
    }
    int min = *min_element(arr,arr+n);
    bool has_output = false;
    for(int i = 0; i < n; i++){
        if(arr[i] == min){
            if(has_output) cout << " ";
            cout << i;
            has_output = true;
        }
    }
    return 0;
}