#include <bits/stdc++.h>
using namespace std;

using triplet = tuple<int, int, int>;
void solve(vector<triplet>& m) {
	sort(m.begin(), m.end());
	vector<triplet> taken;
	taken.reserve(m.size());
	int last = -1;
	
	for(int i = 0; i < (int) m.size(); i++) {
		if (get<1>(m[i]) >= last) {
			taken.push_back(m[i]);
			last = get<0>(m[i]);
		}
	}
	
	sort(taken.begin(), taken.end(), [](triplet a, triplet b) {return get<1>(a) < get<1>(b);});
	for(auto x : taken)
		cout << get<2>(x) << " ";
	cout << '\n';
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	int n, t;
	cin >> t;
	while(t--) {
		cin >> n;
		vector<triplet> m(n);
		for(int i = 0; i < n; i++) {
			cin >> get<1>(m[i]); 
			get<2>(m[i]) = i + 1;
		}
		for(triplet& i : m) cin >> get<0>(i);
		solve(m);
	}
}
