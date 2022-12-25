#include <bits/stdc++.h>

#define ll long long
#define pli pair<ll, int>
#define pil pair<int, ll>
#define pii pair<int,int>
#define ve vector
#define vii ve<pli>
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

int fKaputt = 0;
int fHeile = 0;
int gKaputt = 0;
int gHeile = 0;

vi fassungen;
vi gluehbirnen;
vi arr;
vi result;

void ask(){
    cout << "Q";
    everyN(i){
        cout << " " << arr[i]+1;
    }
    cout << endl;
    everyN(i){
        cin >> result[i];
    }
}

void print(vi &arr){
    for(int x : arr){
        cout << x << " ";
    }
    cout << endl;
}

void buildNew(){
    vi needToSwap;
    everyN(i){
        if(gluehbirnen[arr[i]] != -1 && fassungen[i] != -1){
            needToSwap.push_back(i);
        }
    }
    everyN(i){
        if((gluehbirnen[arr[i]] == -1 || fassungen[i] == -1) && !needToSwap.empty()){
            int j = needToSwap.back();
            needToSwap.pop_back();
            //swap
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }
}

void auswerten(){
    everyN(i){
        if(result[i]){
            if(!(fassungen[i] == 1)){
                fassungen[i] = 1;
                fHeile++;
            }
            if(!(gluehbirnen[arr[i]] == 1)){
                gluehbirnen[arr[i]] = 1;
                gHeile++;
            }
        } else{
            if(gluehbirnen[arr[i]] == 1){
                if(!(fassungen[i] == 0)){
                    fassungen[i] = 0;
                    fKaputt++;
                }
            }
            if(fassungen[i] == 1){
                if(!(gluehbirnen[arr[i]] == 0)){
                    gluehbirnen[arr[i]] = 0;
                    gKaputt++;
                }
            }
        }
    }
}

int count(vi &result){
    int s = 0;
    for(int x : result){
        s += x;
    }
    return s;
}
void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void shuffle(){
    for(int i = 0; i < n-2; i++){
        int j = i + (rand() % (n-i));
        swap(&arr[i], &arr[j]);
    }
}

int main(){
    srand(time(NULL));
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;

    everyN(i){
        arr.push_back(i); 
        result.push_back(0);
        fassungen.push_back(-1);
        gluehbirnen.push_back(-1);
    }
    int c = 0;
    while(fHeile == 0 && gHeile == 0){
        shuffle();
        ask();
        auswerten();
        c++;
        if(c > 100){
            cout << "A";
            everyN(i) cout << " " << i+1;
            cout << endl;
            return 0;
        }
    }/*
    cout << "glueh" << endl;
    print(gluehbirnen);
    cout << "fass" << endl;
    print(fassungen);
*/
    while((fHeile + fKaputt) < n || (gHeile + gKaputt) < n){
        buildNew();
        ask();
        auswerten();
        /*
        cout << "glueh" << endl;
        print(gluehbirnen);
        cout << "fass" << endl;
        print(fassungen);*/
    }

    int j1 = 0;
    int j2 = 0;
    cout << "A";
    everyN(i){
        bool e = false;
        if(fassungen[i]){
            if(j1 >= n) e = true;
            while(gluehbirnen[j1] == 0){
                j1++;
                if(j1 >= n) e = true;
            }
            if(e) cout << " " << ++j2;
            else cout << " " << ++j1;
        } else {
            if(j2 >= n) e = true;
            while(gluehbirnen[j2] == 1){
                j2++;
                if(j2 >= n) e = true;
            }
            if(e) cout << " " << ++j1;
            else cout << " " << ++j2;
        }
    }
    cout << endl;
    return 0;
}