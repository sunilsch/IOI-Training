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

const int maxNodes = 500;

vvll G(maxNodes, vll(maxNodes, INF_LL));
int n,m,l;

void floyd() {
    everyN(k)
        everyN(i)
            everyN(j)
                G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> l;
    everyM(i){
        int n1, n2;
        long long dist;
        cin >> n1 >> n2 >> dist;
        n1--; n2--;
        G[n1][n1] = 0;
        G[n2][n2] = 0;
        G[n1][n2] = min(dist,G[n1][n2]);
        G[n2][n1] = min(dist,G[n2][n1]);
    }
    floyd();
    
    for(int i = 0; i < l; i++){
        int n1,n2;
        cin >> n1 >> n2;
        n1--; n2--;
        cout << ((G[n1][n2] == INF_LL) ? -1 : G[n1][n2]) << endl;
    }
    return 0;
}