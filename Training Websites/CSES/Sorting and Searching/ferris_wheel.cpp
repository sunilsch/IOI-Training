#include <bits/stdc++.h>

using namespace std;

const int maxn=2e5+10;

int n,x,p[maxn],i,j,ans=0;
bool have_gondola[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> x;
    for(int i = 0; i < n; i++) cin >> p[i];
    sort(p, p + n);
    i = 0; j = n - 1;
    while(i < j){
        if(p[i]+p[j]>x) j--;
        else{
            ans++;
            have_gondola[i]=have_gondola[j]=true;
            i++; j--;
        }
    }
    for(int i = 0; i < n; i++) ans += have_gondola[i] == false;
    cout << ans << endl;
    
    return 0;
}