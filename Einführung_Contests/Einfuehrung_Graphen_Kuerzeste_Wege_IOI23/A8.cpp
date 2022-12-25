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

int n;
ve<pii> bauern1;
ve<pii> bauern2;

int solve(vi &bauern){
    vi endings = {0};
    for ( int i = 0; i < n; i++ ) {
        int j = lower_bound(endings.begin(), endings.end(), bauern[i]) - endings.begin();
        if (j == endings.size()){
			endings.push_back(bauern[i]);
		} else {
            endings[j] = bauern[i];
		}
        for(int x : endings){
            cout << x << " ";
        }
        cout << endl;
    }
    return endings.size() - 1;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    test{
        cin >> n;
        everyN(i){
            int iq, gewicht;
            cin >> iq >> gewicht;
            bauern1.emplace_back(iq, gewicht);
            bauern2.emplace_back(gewicht, iq);
        }
        sort(bauern1.begin(), bauern1.end());
        sort(bauern2.begin(), bauern2.end());
        reverse(bauern2.begin(), bauern2.end());
        vi bauernGewichte;
        vi bauernIQ;
        for(auto x : bauern1){
            bauernGewichte.push_back(x.second);
        }
        for(auto x : bauern2){
            bauernIQ.push_back(x.second);
        }
        reverse(bauernGewichte.begin(), bauernGewichte.end());
        reverse(bauernIQ.begin(), bauernIQ.end());
        int x1 = solve(bauernGewichte);
        int x2 = solve(bauernIQ);
        cout << "Case #" << t+1 << ": " << x1 << x2 << endl;
        bauern1.clear();
        bauern2.clear();
    }
    
    return 0;
}