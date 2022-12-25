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

int n, b, h, w;
bool finish = false;
int sol = INF_INT;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    test{
        cin >> n >> b >> h >> w;
        for(int i = 0; i < h; i++){
            int p;
            cin >> p;
            for(int j = 0; j < w; j++){
                int a;
                cin >> a;
                if(a >= n && n*p <= b){
                    finish = true;
                    sol = min(sol, n*p);
                }
            }

        }
        if(!finish){
            cout << "Case #" << t+1 << ": stay home" << endl;
        } else {
            
            cout << "Case #" << t+1 << ": " << sol << endl;
        }
        finish = false;
        sol = INF_INT;
    }
    
    return 0;
}