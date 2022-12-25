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

int n, m, n1, n2, ans=0, ans2=0;
bool isPossible = true;
const int maxNodes = 300001;

vvi G(maxNodes);
ve<bool> visited(maxNodes, false);
ve<bool> group(maxNodes);

void dfs(int node, int parent){
    visited[node] = true;
    for(int nextNode : G[node]){
        if(nextNode != parent){
            if(!visited[nextNode]){
                group[nextNode] = !group[node];
                if(group[nextNode]) ans++;
                else if(!group[nextNode]) ans2++;
                dfs(nextNode, node);
            } else {
                if(group[nextNode] == group[node]){
                    isPossible = false;
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    everyM(i){
        cin >> n1 >> n2;
        n1--; n2--;
        G[n1].push_back(n2);
        G[n2].push_back(n1);
    }
    int gesamt = 0;
    everyN(i){
        ans = 0, ans2 = 1;
        if(!visited[i]){
            dfs(i,-1);
            gesamt += max(ans, ans2);
        }
    }
    if(isPossible){
        cout << "JA" << endl;
        cout << gesamt << endl;
    } else {
        cout << "NEIN" << endl;
    }


    return 0;
}