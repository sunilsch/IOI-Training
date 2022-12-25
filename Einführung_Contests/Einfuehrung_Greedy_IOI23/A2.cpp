#include <bits/stdc++.h>

using namespace std;

// global vars

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int l,r;
    cin >> l >> r;
    if(l != r){
        cout << "Odd " << 2*(l > r ? l : r);
    } else {
        if(l!=0){
            cout << "Even " << l+r;
        } else {
            cout << "Not a moose ";
        }
    }
    
    return 0;
}