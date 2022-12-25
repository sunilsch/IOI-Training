#include <bits/stdc++.h>

using namespace std;

int n,m;
char A[1000][1000];
bool vis[1000][1000];

int previousStep[1000][1000];

int dx[4] = { -1, 0, 1, 0 };

int dy[4] = { 0, 1, 0, -1 };

string stepDir = "URDL";

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;

    queue<pair<int,int>> q;
    pair<int,int> begin, end;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> A[i][j];
            if (A[i][j] == 'A') {
				begin = make_pair(i, j);
			} else if (A[i][j] == 'B') {
				end = make_pair(i, j);
            }
        }
    }
    q.push(begin);
    vis[begin.first][begin.second] = true;

    while(!q.empty()){
        pair<int,int> u = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            pair<int,int> v = make_pair(u.first + dx[i], u.second + dy[i]);
            if (v.first < 0 || v.first >= n || v.second < 0 || v.second >= m) continue;
            if (A[v.first][v.second] == '#') continue;
            if (vis[v.first][v.second]) continue;
            vis[v.first][v.second] = true;
            previousStep[v.first][v.second] = i;
            q.push(v);
        }
    }

    if(vis[end.first][end.second]){
        cout << "YES" << endl;
        vector<int> steps;
        while (end != begin){
            int p = previousStep[end.first][end.second];
            steps.push_back(p);
            end = make_pair(end.first - dx[p], end.second - dy[p]);
        }
        reverse(steps.begin(), steps.end());

        cout << steps.size() << endl;
        for(char c : steps) {
            cout << stepDir[c];
        }
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}