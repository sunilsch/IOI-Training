#include <bits/stdc++.h>

#define ll long long
#define pli pair<ll, int>
#define pil pair<int, ll>
#define pii pair<int,int>
#define ve vector
#define vi ve<int>
#define vb ve<bool>
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

const int maxNodes = 1000;

vvi G(maxNodes);
vb visited(maxNodes, false);
vb finished(maxNodes, false);
vi result;
bool possible = true;

int n, m, l, a=0;

void visit(int node){
    visited[node] = true;
    for(int newNode : G[node]){
        if(!visited[newNode]){
            visit(newNode);
        }
        if(visited[newNode] && !finished[newNode]){
            possible = false;
        }
    }
    finished[node] = true;
    result.push_back(node);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    test{
        cin >> n >> m >> l;
        everyM(i){
            int n1, n2;
            cin >> n1 >> n2;
            n1--; n2--;
            G[n1].push_back(n2);
        }
        for(int i = 0; i < n; i++){
            if(!visited[i])
                visit(i);
        }
        reverse(result.begin(), result.end());
        vi nResult(n);
        everyN(i){
            nResult[result[i]] = i;
        }


        cout << "Case #" << t+1 << ": ";
        if(!possible){
            cout << "no" << endl;
            for(int i = 0; i < l; i++){
                int n1, n2;
                cin >> n1 >> n2;
            }
        } else {
            cout << "yes" << endl;
            for(int i = 0; i < l; i++){
                int n1, n2;
                cin >> n1 >> n2;
                n1--; n2--;
                if(nResult[n1] < nResult[n2]){
                    cout << n1+1 << " " << n2+1 << endl;
                } else {
                    cout << n2+1 << " " << n1+1 << endl;
                }
            }
        }
        everyN(i){
            G[i].clear();
            visited[i] = false;
            finished[i] = false;
        }
        a = 0;
        possible = true;
        result.clear();
    }
    return 0;
}