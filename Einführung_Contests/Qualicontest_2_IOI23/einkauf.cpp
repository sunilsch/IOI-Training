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
double var;
ve<double> geschenke;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    everyN(i){
        cin >> var;
        geschenke.push_back(var);
    }
    sort(geschenke.begin(), geschenke.end());
    reverse(geschenke.begin(), geschenke.end());
    int ans;
    ve<double> save(n+5, INF_INT);
    for(int i = 0; i < n; i++){
        double one = geschenke[i];
        double two = geschenke[i] + (geschenke[i+1] / 2);
        double three = geschenke[i] + geschenke[i+1];
        if(save[i] == INF_INT){
            save[i+1] = one;
            save[i+2] = two;
            save[i+3] = three;
        } else {
            save[i+1] = min(save[i] + one, save[i+1]);
            save[i+2] = min(save[i] + two, save[i+2]);
            save[i+3] = min(save[i] + three, save[i+3]);
        }
        
    }

    cout << (int)save[n] << " Euro " << (save[n] - (int)save[n])*100 << " Cent"<< endl;
    
    return 0;
}