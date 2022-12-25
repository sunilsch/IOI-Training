#include <bits/stdc++.h>

using namespace std;

int n,m,sum_of_rooms=0;
char grid[1010][1010];
bool visited[1010][1010];

int nX[4] = {0,0,1,-1};
int nY[4] = {1,-1,0,0};

bool isValid(int y, int x){
    if(y < 0) return false;
    if(x < 0) return false;
    if(y >= n) return false;
    if(x >= m) return false;
    if(grid[y][x] == '#') return false;
    return true;
}

void explore_room(int y, int x){
    visited[y][x] = true;
    for(int i = 0; i < 4; i++){
        int newX = x + nX[i];
        int newY = y + nY[i];
        if(isValid(newY, newX)){
            if(!visited[newY][newX]){
                explore_room(newY, newX);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
            visited[i][j] = false;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == '.' && !visited[i][j]){
                explore_room(i,j);
                sum_of_rooms++;
            }
        }
    }
    cout << sum_of_rooms;
    return 0;
}