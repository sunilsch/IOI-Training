#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	
	int l, r;
	cin >> l >> r;

	if (l == 0 && r == 0)
		cout << "Not a moose\n";
	else if (l == r)
		cout << "Even " << l*2 << endl;
	else
		cout << "Odd " << max(l,r)*2 << endl;
}
