#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        string res = "impossible";
        string input;
        cin >> input;
        int w=0,b=0;
        for(int j = 0; j < input.length(); j++){
            if(input[j] == 'W'){
                w++;
            } else {
                b++;
            }
        }
        if(w == b){
            res = "possible";
        }
        cout << "Case #" << i << ": " << res << endl;
    }
    return 0;
}
