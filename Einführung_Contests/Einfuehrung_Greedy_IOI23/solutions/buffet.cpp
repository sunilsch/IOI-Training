#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	vector<pair<double,int>> food(n);
	for (int i = 0; i < n; i++){
		string name;
		int amount;
		double nom;
		cin >> name >> amount >> nom;
		food[i] = {nom, amount};
	}
	sort(food.begin(), food.end());

	double total = 0;
	for (int i = n-1; i >= 0; i--){
		int amount = food[i].second;
		double nom = food[i].first;
		
		if (m >= amount){
			total += nom * amount;
			m -= amount;
		} else {
			total += nom * m;
			break;
		}
	}

	cout << fixed << setprecision(10) << total << endl;
	return 0;
}