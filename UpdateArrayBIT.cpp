#include <bits/stdc++.h>
using namespace std;
 
/*
* Updated version with the Fenwick Tree
*/
 
inline void add(vector<int>& tree, int i, int v) { 
	for (++i; i < tree.size(); i += i&-i) 
		tree[i] += v;
}
  
inline int64_t sum(vector<int>& tree, int i) {
	int64_t s = 0;
	for (++i; i > 0; i &= i-1) 
		s += tree[i];
			
	return s;
}
	
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
		
	int t, n, u, q, v, l, r;
	cin >> t;
	while(t--) {
		cin >> n >> u;
		vector<int> diff(n + 1, 0);
			
		while(u--) {
			cin >> l >> r >> v;
			add(diff, l, v);
			add(diff, r + 1, -v);
		}
			
		cin >> q;
		int last = 0;
		while(q--) {
			cin >> v;
			cout << sum(diff, v) << '\n';
		}
	}	
}
