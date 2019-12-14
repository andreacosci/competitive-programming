#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n; 

	cin >> n;
	int count = min(2, n);
	vector<pair<int, int>> tree(n);
	for(auto& t : tree) 
		cin >> t.first >> t.second;
		
	sort(tree.begin(), tree.end());
	for(int i = 1; i < n-1; i++) {
		if (tree[i].first - tree[i].second > tree[i-1].first) {
			count++;
		}
		else if (tree[i].first + tree[i].second < tree[i+1].first) {
			count++;
			tree[i].first += tree[i].second;
		}
	}
	
	cout << count;
		
	return 0;
}
