#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	
    int n = 0;
    cin >> n;
    long long m = -1;
    for (int i = 0; i < n; i++){
        long long tmp;
        cin >> tmp;
        m = max(tmp, m);
    }
    cout << m*m*m << endl;
    return 0;
}