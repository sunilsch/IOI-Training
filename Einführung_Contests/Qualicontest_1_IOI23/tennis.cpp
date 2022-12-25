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

int n, var;
ve<pii> ETA;
ve<pii> PWA;
vi notUsed;
ve<pii> matches;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    everyN(i){
        cin >> var;
        ETA.emplace_back(var, i+1);
    }
    everyN(i){
        cin >> var;
        PWA.emplace_back(var, i+1);
    }
    sort(ETA.begin(), ETA.end());
    sort(PWA.begin(), PWA.end());
    int i = 0, j = 0;
    while(i < n && j < n){
        while(!(ETA[i].first < PWA[j].first)){
            //notUsed.push_back(PWA[j].second);
            j++;
        }
        if(j >= n) break;
        //matches.emplace_back(ETA[i].second, PWA[j].second);
        j++; i++;
    }
    cout << i << endl;
    /*
    for(auto x : matches){
        cout << x.first << " " << x.second << endl;
    }
    j = 0;
    while(i < n){
        cout << ETA[i].second << " " << notUsed[j] << endl;
        j++; i++;
    }*/
    return 0;
}