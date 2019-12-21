#include <bits/stdc++.h>
using namespace std;

void modify(vector<int>& t, int n, int p, int value) {  
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
}

int query(vector<int>& t, int n, int l, int r) { 
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += t[l++];
    if (r&1) res += t[--r];
  }
  return res;
}

typedef struct _interval {
	int left;
	int right;
	int idx;
} Interval;

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<Interval> in(n);
	vector<int> res(n);
	vector<int> remap;
	remap.reserve(2*n);
	
	for(int i = 0; i < n; i++) {
		in[i].idx = i;
		cin >> in[i].left >> in[i].right;
		remap.push_back(in[i].left);
		remap.push_back(in[i].right);
	}
	
	sort(remap.begin(), remap.end());
	for(int i = 0; i < n; i++) {
		in[i].left   = lower_bound(remap.begin(), remap.end(), in[i].left) - remap.begin() + 1;
		in[i].right  = lower_bound(remap.begin(), remap.end(), in[i].right) - remap.begin() + 1;
	}
	
	vector<int> tree(8*n, 0);
	sort(in.begin(), in.end(), [](Interval& a, Interval& b) { if (a.left == b.left) return a.right < b.right; else return a.left > b.left;
	});

	for(Interval& i : in) {
		res[i.idx] = query(tree, 2*n, i.left + 1, i.right);
		modify(tree, 2*n, i.right, 1);
	}
	
	for(auto x : res)
		cout << x <<'\n'; 
	
	return 0;
}
