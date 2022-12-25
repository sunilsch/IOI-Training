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
ve<pii> bauern;

int solve(){
    vi endings = {0};
    everyN(i){
        int a = lower_bound(endings.begin(), endings.end(), bauern[i].second) - endings.begin();
        if (a == endings.size()){
            endings.push_back(bauern[i].second);
        } else {
            endings[a] = bauern[i].second;
        }
    }
    return endings.size() - 1;
}
bool compare(pii a, pii b){
    if(a.first > b.first) return true;
    else if(a.first < b.first) return false;
    else return a.second < b.second;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    test{
        cin >> n;
        if(n == 0){
            cout << "Case #" << t+1 << ": " << 0 << endl;
            continue;
        }
        everyN(i){
            int var1, var2;
            cin >> var1 >> var2;
            bauern.emplace_back(var1, var2);
        }
        sort(bauern.begin(), bauern.end(), compare);
        cout << "Case #" << t+1 << ": " << solve() << endl;
        bauern.clear();
    }
    return 0;
}