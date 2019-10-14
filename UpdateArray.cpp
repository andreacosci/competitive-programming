#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int t, n, u, q, v, l, r;
	cin >> t;
	while(t--) {
		cin >> n >> u;
		vector<int64_t> diff(n + 1, 0);
		
		while(u--) {
			cin >> l >> r >> v;
			diff[l] += v;
			diff[r + 1] -= v;
		}
		
		for(int i = 1; i < n; i++) {
			diff[i] += diff[i - 1];
		}
		
		cin >> q;
		int last = 0;
		while(q--) {
			cin >> v;
			cout << diff[v] << '\n';
		}
	}
}
