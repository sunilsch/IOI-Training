#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        int l, n, r;
        cin >> l >> n >> r;

        vector<int> pos(n);
        for (int i = 0; i < n; i++) {
            cin >> pos[i];
        }
        sort(pos.begin(), pos.end());
        pos.push_back(l + (r*10));

        int last = -r;
        int lastPossible = -r;
        int count = 0;
        bool fail = true;
        for (int i = 0; i <= n; i++){
            int curr = pos[i];
            if (curr - last <= 2*r){
                lastPossible = curr;  //possible
            } else {
                if (last != lastPossible){
                    last = lastPossible;  //take lastPossible
                    count++;
                    i--;  //reconsider curr

                    if (l - last <= r){
                        fail = false;
                        break;  //finished
                    }
                } else {
                    break;  //not possible
                }
            }
        }

        
        cout << "Case #" << t << ": ";
        if(fail) {
            cout << "impossible" << endl;
        } else {
            cout << count << endl;
        }
    }
}