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

const int maxNodes = 100000;
int n, m;
vi maxPath;
vvi G(maxNodes);

void dfs(int node, int dist, vi &path){
    path.push_back(node);
    if(node == n-1 && path.size() > maxPath.size()){
        maxPath = path;
    }
    for(int nextNode : G[node]){
        dist++;
        dfs(nextNode, dist, path);
    }
    path.pop_back();
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    int last1, last2;
    everyM(i){
        int var1, var2;
        cin >> var1 >> var2;
        var1--; var2--;
        if(last1 == var1 && last2 == var2){
            last1 = var1; last2 = var2;
            continue;
        }
        G[var1].push_back(var2);
        last1 = var1; last2 = var2;
    }
    vi path;
    dfs(0, 0, path);
    if(maxPath.size() == 0){
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << maxPath.size() << endl;
        for(int x : maxPath){
            cout << x+1 << " ";
        }
        cout << endl;
    }
    
    return 0;
}