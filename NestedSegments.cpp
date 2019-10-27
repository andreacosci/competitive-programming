#include <bits/stdc++.h>

using namespace std;
typedef tuple<int, int, int> triplets;

void add(vector<int>& ftree, int i, int v) {
	for(++i; i < ftree.size(); i += i&-i)
		ftree[i] += v;
}

int sum(vector<int>& ftree, int i) {
	int sum = 0;
	
	for(++i; i > 0; i&=i-1) {
		sum += ftree[i];
	}
	
	return sum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<triplets> v(n);
	vector<int> remap, res(n); 
	remap.reserve(2*n);
	
	for(int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		get<0>(v[i]) = a;
		get<1>(v[i]) = b;
		get<2>(v[i]) = i;
		remap.push_back(a); remap.push_back(b);
	}
	
	sort(remap.begin(), remap.end());
	for(int i = 0; i < n; i++) {
		get<0>(v[i]) = lower_bound(remap.begin(), remap.end(), get<0>(v[i])) - remap.begin();
		get<1>(v[i]) = lower_bound(remap.begin(), remap.end(), get<1>(v[i])) - remap.begin();
	}
	
	sort(v.rbegin(), v.rend());
	
	vector<int> ftree(remap.size() + 1, 0);
	for(int i = 0; i < n; i++) {
		res[get<2>(v[i])] = sum(ftree, get<1>(v[i])) - sum(ftree, get<0>(v[i]));
		add(ftree, get<1>(v[i]), 1);
	}
	
	for(int& x : res) 
		cout << x << '\n';
		
	return 0;	
	
}
