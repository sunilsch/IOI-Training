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

string input;
/*
int index = -1;
int calculate(){
    index++;
    cout << "node" << "Index: " << index << " childs" << input[index] << endl;
    int k;
    if(input[index] == '1'){
        int k = calculate();
    } else if(input[index] == '2'){
        int k1 = calculate();
        int k2 = calculate();
    }
    return k;
}

*/
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> input;
    

    // 10 points
    int a = 1;
    for(int i = 0; input[i] == '1'; i++){
        a++;
    }
    cout << "0 " << (((a % 2) == 0) ? a / 2 : a / 2 + 1) << endl;

    
    
    return 0;
}