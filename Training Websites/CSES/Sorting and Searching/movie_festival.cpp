#include <bits/stdc++.h>

using namespace std;

// global vars

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x, y, curr_end = 0, total = 0;
	vector<pair<int, int>> arr;
	cin >> n;
	while (n--){
		cin >> x >> y;
		arr.push_back(make_pair(y, x));
	}
	sort(arr.begin(), arr.end());
	for (auto ele : arr){
		if (ele.second >= curr_end){
			curr_end = ele.first;
			total++;
		}
	}
	cout << total;
    
    return 0;
}