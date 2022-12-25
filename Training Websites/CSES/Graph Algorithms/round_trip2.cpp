#include <bits/stdc++.h>

using namespace std;

const int maxNodes = 100000;

vector<bool> visited(maxNodes, false);
vector<bool> isInStack(maxNodes, false);
vector<vector<int>> G(maxNodes);
stack<int> recursionStack;
int n, m;

bool visit(int node){
    visited[node] = true;
    recursionStack.push(node);
    isInStack[node] = true;
    for(int newNode : G[node]){
        if(!visited[newNode]){
            if(visit(newNode)){
                return true;
            }
        }
        if(isInStack[newNode]){
            recursionStack.push(newNode);
            return true;
        }
    }
    recursionStack.pop();
    isInStack[node] = false;
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int n1, n2;
        cin >> n1 >> n2;
        n1--; n2--;
        G[n1].push_back(n2);
    }

    for (int i = 0; i < n; i++)
    {
        if(!visited[i]){
            if(visit(i)){
                vector<int> ans;
                int temp = recursionStack.top()+1;
                while(!recursionStack.empty()){
                    ans.push_back(recursionStack.top()+1);
                    recursionStack.pop();
                    if(ans.back() == temp and ans.size() != 1){
                        break;
                    }
    			        
                }
                reverse(ans.begin(), ans.end());
                
                cout << ans.size() << endl;
                for(int node : ans)
                    cout << node << " ";
                return 0;
            }
        }
        
    }
    cout << "IMPOSSIBLE" << endl;
    
    return 0;
}