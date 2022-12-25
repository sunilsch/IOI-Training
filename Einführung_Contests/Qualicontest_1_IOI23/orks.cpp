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

int n, m, asked;
bool hole;
ve<pii> directions = {
    {1,0},
    {-1,0},
    {0, 1},
    {0,-1}
};
int ask(int x, int y){
    asked++;
    cout << "1 " << x+1 << " " << y+1 << endl;
    int ans;
    cin >> ans;
    return ans;
}

void discover(int x, int y, vvi &grid, bool fill, ve<ve<bool>> &vis, int parX, int parY){
    vis[x][y] = true;
    if(grid[x][y] == 1){
        grid[parX][parY] = ask(parX, parY);
    } else {
        if(grid[x][y] != 0){
            if(fill) grid[x][y] = 0;
            for(auto direction : directions){
                int xNew = x+direction.first, yNew = y+direction.second;
                if(xNew >= 0 && xNew < m && yNew >= 0 && yNew < n && !vis[xNew][yNew]){
                    discover(xNew, yNew, grid, fill, vis, x, y);
                }
            }
        }
    }
}

bool fillHole(int x, int y, vvi &grid){
    ve<ve<bool>> vis(m, ve<bool>(n, false));
    hole = true;
    discover(x,y,grid, false, vis, -1, -1);
    if(hole){
        everyM(i){
            vis[i].resize(n, false);
        }
        discover(x, y, grid, true, vis, -1, -1);
        return true;
    } else {
        return false;
    }
}
void handlePoint(int x, int y, vvi &grid){
    int n1 = 0, n2 = 0;
    for(auto direction : directions){
        int xNew = x+direction.first, yNew = y+direction.second;
        if(xNew >= 0 && xNew < m && yNew >= 0 && yNew < n){
            int a = grid[xNew][yNew];
            if(a == 0) n1++;
            else if (a == 1) n2++;
        } else {
            n1++; n2++;
        }
    }
    if(n1 == 4){
        grid[x][y] = 0;
    } else if(n2 == 4){
        grid[x][y] = 1;
    } else {
        grid[x][y] = ask(x, y);
    }
    if(grid[x][y] == 0) fillHole(x, y, grid);
    for(auto direction : directions){
        int xNew = x+direction.first, yNew = y+direction.second;
        if(xNew >= 0 && xNew < m && yNew >= 0 && yNew < n){
            if(grid[xNew][yNew] == -1)
                handlePoint(xNew, yNew, grid);
        }
    }
    
    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> m >> n;
    vvi grid(m, vi(n, -1));
    int x, y;
    cin >> x >> y;
    x--; y--;
    grid[x][y] = 1;
    for(auto direction : directions){
        int xNew = x+direction.first, yNew = y+direction.second;
        if(xNew >= 0 && xNew < m && yNew >= 0 && yNew < n){
            if(grid[xNew][yNew] == -1)
                handlePoint(xNew, yNew, grid);
        }
        
    }
    cout << 2 << endl;
    everyN(i){
        everyM(j){
            cout << grid[j][i] << " ";
        }
        cout << endl;
    }
    cout << asked << endl;
    return 0;
}