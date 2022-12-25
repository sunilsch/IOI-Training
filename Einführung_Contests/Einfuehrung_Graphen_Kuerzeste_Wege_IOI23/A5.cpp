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
vi bestTour;
ll bestWeight = INF_LL;
void generateTour(vi tour, ll weight, vvll &G, ve<bool> visited, int node){
    visited[node] = true;
    if(node != 0){
        weight+=G[tour.back()][node];
    }
    
    tour.push_back(node);
    if(tour.size() < n){
        everyN(i){
            if(!visited[i]){
                generateTour(tour, weight, G, visited, i);
            }
        }
    } else {
        if(weight+G[node][0] < bestWeight){
            bestTour = tour;
            bestWeight = weight+G[node][0];
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    test{
        cin >> n;
        vvll G(n, vll(n));
        everyN(i){
            everyN(j){
                int var;
                cin >> var;
                G[i][j] = var;
            }
        }
        generateTour(vi(), 0, G, ve<bool>(n), 0);
        cout << "Case #" << t+1 << ": ";
        for(int x : bestTour){
            cout << x+1 << " ";
        }
        cout << endl;
        bestWeight = INF_LL;
        bestTour.clear();
    }
    
    
    return 0;
}