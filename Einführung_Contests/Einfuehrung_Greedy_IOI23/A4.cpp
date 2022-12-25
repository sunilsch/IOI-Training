#include <bits/stdc++.h>

using namespace std;

// global vars

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t, l, n, r, lighted, turnedOn;
    bool impossible;
    vector<int> positons;
    cin >> t;
    for (int ti = 0; ti < t; ti++)
    {
        lighted = 0;
        turnedOn = 0;
        impossible = false;
        positons.clear();
        cin >> l >> n >> r;
        for(int i = 0; i < n; i++){
            int p;
            cin >> p;
            positons.push_back(p);
        }
        if(n == 0 || r == 0){
            cout << "Case #" << ti+1 << ": impossible" << endl;
            continue;
        }
        sort(positons.begin(), positons.end());
        for(int i = 0; i < n-1; i++){
            if(positons[i+1]-r > lighted){
                if(positons[i]-r > lighted){
                    impossible = true;
                    break;
                }
                turnedOn++;
                lighted = positons[i]+r;
            }
        }
        if(lighted < l){
            if(positons.back()+r >= l && positons.back()-r <= lighted){
                turnedOn++;
            } else {
                impossible = true;
            }
        }
        if(!impossible) cout << "Case #" << ti+1 << ": " << turnedOn << endl;
        else cout << "Case #" << ti+1 << ": impossible" << endl;
    }
    return 0;
}