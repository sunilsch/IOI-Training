#include <bits/stdc++.h>

using namespace std;

#define MAXN 100000

int n,m;
vector<int> adj[MAXN][2];
bool visited[MAXN];
vector<int> bridges;


void DFS(int node, int x){
    visited[node] = true;
    for (int child : adj[node][x]){
        if(visited[child] == false) {
            DFS(child, x);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int node1, node2;
        cin >> node1 >> node2;
        node1--;node2--;
        adj[node1][0].push_back(node2);
        adj[node2][1].push_back(node1);
    }
    DFS(0, 0);
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			cout << "NO" << endl;
			cout << 1 << " " << i + 1 << endl;
			return 0;
		}
	}

	memset(visited, false, sizeof(visited));
    
    DFS(0, 1);
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			cout << "NO" << endl;
			cout << i + 1 << " " << 1 << endl;
			return 0;
		}
	}
    cout << "YES" << '\n';
    return 0;
}