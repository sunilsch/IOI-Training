#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string input;
    cin >> input;
    char last = input[0];
    int seq = 0;
    int maxi = 0;
    for(char x:input){
        if(x == last) seq+=1;
        else{
            maxi = max(maxi, seq);
            seq=1;
        }
        last = x;
    }
    maxi = max(maxi, seq);
    cout << maxi;
    return 0;
}