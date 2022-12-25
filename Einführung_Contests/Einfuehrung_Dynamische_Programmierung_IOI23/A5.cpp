#include <bits/stdc++.h>

#define ll long long
#define pli pair<ll, int>
#define pil pair<int, ll>
#define pii pair<int,int>
#define ve vector
#define vi ve<int>
#define vll ve<ll>
#define vvll ve<vll>
#define vvi ve<vi>
#define vvvi ve<vvi>
#define everyN(var) for(int var = 0; var < n; var++)
#define everyM(var) for(int var = 0; var < m; var++)
#define test int tins; cin >> tins; for(int t = 0; t < tins; t++)
#define INF_INT numeric_limits<int>::max()/2
#define INF_LL numeric_limits<long long>::max()/2

using namespace std;

int c, m;
const int maxCM = 102;
vvi schueler(maxCM, vi(maxCM, 0));

int max_value() {
    int max_w = c;
    c++;
    vi last(max_w + 1, -1);
    for (int i = 0; i < c; i++) {
        last[i] = max(last[i], schueler[0][i]);
    }

    vector<int> current(max_w + 1);
    for (int i = 1; i < m; ++i) {
        fill(current.begin(), current.end(), -1);
        for (int j = 0; j < c; ++j) {
            for (int k = j; k <= max_w; ++k) {
                if (last[k - j] >= 0)
                    current[k] = max(current[k], last[k - j] + schueler[i][j]);
            }
        }
        swap(current, last);
    }

    return *max_element(last.begin(), last.end());
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> c >> m;
    everyM(i){
        for(int j = 1; j <= c; j++){
            int var;
            cin >> var;
            schueler[i][j] = var;
        }
    }
    cout << max_value() << endl;
    
    return 0;
}