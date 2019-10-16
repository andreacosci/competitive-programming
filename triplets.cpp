#include <bits/stdc++.h>

/**
 * Not part of homeworks.
 * A nLog(n) solution for 14/02/18 exam
 * 
 */ 

using namespace std;
inline void add(vector<int>& tree, int i, int v) {
	for(++i; i < tree.size(); i += i&-i)
		tree[i] += v;
}

inline int64_t sum(vector<int>& tree, int i) {
	int64_t sum = 0;
	for(++i; i > 0; i -= i & -i)
		sum += tree[i];
		
	return sum;
}


int main() {
	ios_base::sync_with_stdio(false);
	int n, lft, rgt = 0;
	int triplets = 0; 
	cin >> n;
	vector<int> a(n), s(n), g(n);
	
	for(int& x : a)
		cin >> x;
		
	vector<int> ftree(n + 1, 0);
	
	//Elements on the right greater than i
	for(int i = n -1; i >= 0;  i--) {
		g[i] = sum(ftree, n - a[i] - 1);
		add(ftree, n - a[i] - 1, 1);
	}
	
	fill(ftree.begin(), ftree.end(), 0);
	//Elements on the left smaller than i
	for(int i = 0; i < n; i++) {
		s[i] = sum(ftree, a[i] - 1);
		add(ftree, a[i], 1);
	}
	
	for(int i = 0; i < n; i++)
		triplets += s[i] * g[i];
		
	cout << triplets; 
}
