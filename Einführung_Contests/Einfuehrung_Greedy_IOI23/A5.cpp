#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph(100000);
map<string,int> names;
vector<bool> visited;
vector<bool> finished;
int n;
bool possible = true;
void visit(int v){
    visited[v] = true;
    for(int i : graph[v]){
        if(!visited[i]){
            visit(i);
        }
        if(visited[i] && !finished[i]){
            possible = false;
            return;
        }
    }
    finished[v] = true;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int a = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        string name1, name2;
        char o;
        cin >> name1 >> o >> name2;
        if(!names.count(name1)){
            names[name1] = a;
            a++;
        }
        if(!names.count(name2)){
            names[name2] = a;
            a++;
        }
        if(o == '>'){
            graph[names[name1]].push_back(names[name2]);
        } else {
            graph[names[name2]].push_back(names[name1]);
        }
    }
    for(int i = 0; i < names.size(); i++){
        visited.push_back(false);
        finished.push_back(false);
    }

    for(int i = 0; i < n; i++){
        if(!visited[i]){
            visit(i);
        }
    }
    cout << (possible ? "possible" : "impossible");
    return 0;
}