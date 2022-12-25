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

unsigned long long n;
unsigned long long money = 100;
unsigned long long moneySave = 0;
unsigned long long akt = 0;
ve<unsigned ll> kurs;
bool haveMoney = true;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(unsigned long long i = 0; i < n; i++){
        unsigned long long var;
        cin >> var;
        kurs.push_back(var);
    }
    for(unsigned long long i = 0; i < n-1; i++){
        if(haveMoney){
            if(kurs[i+1] > kurs[i]){
                akt = money / kurs[i];
                moneySave = money % kurs[i];
                
                if(akt > 100000){
                    moneySave += (akt-100000)*kurs[i];
                    akt = 100000;
                }
                haveMoney = false;
            }
        } else {
            if(kurs[i+1] < kurs[i]){
                money = (akt * kurs[i]) + moneySave;
                haveMoney = true;
            }
        }
    }
    if(!haveMoney){
        money = (akt * kurs[n-1]) + moneySave;
    }
    cout << money << endl;
    
    return 0;
}
