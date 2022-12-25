#include <bits/stdc++.h>

using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int nCases, nTroops, Ci, Ti, Si, time, sand = 0, oldCi, oldTi, oldSi;
    cin >> nCases;
    for(int i = 0; i < nCases; i++){
        cin >> nTroops;
        time = 0;
        
        cin >> Ci >> Ti >> Si;
        for(int j = 0; j < nTroops-1; j++){
            oldCi = Ci, oldTi = Ti, oldSi = Si;
            cin >> Ci >> Ti >> Si;
            int nToGet = min(Si - time, Ci);
            int nToGetOld = min(oldSi - time, oldCi);
            if(oldSi >= Si){
                for(int k = 0; k < oldCi; k++){
                    if(oldTi > time){
                        time++;
                        sand+=oldSi;
                    }
                }
            } else {
                for(int k = 0; k < max(1, nToGetOld-nToGet); k++){
                    if(oldTi > time){
                        time++;
                        sand+=oldSi;
                    }
                }
            }
        while(Ti > time){
            time++;
            sand+=Si;
        }

        }
    }
    cout << sand;
    return 0;
}