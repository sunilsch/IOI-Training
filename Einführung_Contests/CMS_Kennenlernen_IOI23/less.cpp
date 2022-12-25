#include <bits/stdc++.h>

using namespace std;

bool ask(long long n){
    cout << "Q " << n << endl;
    char answer;
    cin >> answer;
    return answer == 'y';
}


long long search(long long left, long long right){
    if(left == right){
        return left;
    } else if((right-left) == 1){
        if(ask(right)){
            return left;
        } else {
            return right;
        }
    }
    long long mid = (left + right) / 2;
    if(ask(mid)){
        return search(left, mid-1);
    } else {
        return search(mid, right);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    long long ans = search(0, 1e9);
    cout << "A " << ans << endl;
    
    return 0;
}