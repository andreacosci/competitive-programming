#include <bits/stdc++.h>
using namespace std;
/**
 * Not for homework.
 * Exam : 14/01/19
 * Time: (n + q) log n
 */ 

typedef tuple<int, int, int, int> quadruple;

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
	int n, q; 
	cin >> n >> q;
	vector<quadruple> array(n + q);
	vector<int> ans(q + 1);
	
	/**
	 * Put everything in the same array as quadruple.
	 * value, query_pos (0 if not a query), left bound (0 if not a query),
	 * right_bound (or pos in the original array)]
	 */ 
	for(int i = 0; i < n; i++) {
		int tmp; 
		cin >> tmp;
		array[i] = make_tuple(tmp, 0, 0, i);
	}
	
	for(int i = 0; i < q; i++) {
		int l, r, x;
		cin >> l >> r >> x;
		array[i + n] = make_tuple(x, i + 1, l, r);
	}
	
	/**
	 * By sorting we will find (in case of value collision)
	 * array's element first. So we put them in the fenwick tree.
	 * When we'll find L R X query, in the range L R we will find
	 * ones equals to the number of elements smaller than X we found 
	 * before. So the prefix sum in range L R will be the answer.
	 */ 
	sort(array.begin(), array.end());
		
	vector<int> ftree(n + 1, 0);
	
	for(const quadruple& t : array) {
		if (get<1>(t) != 0) {
			ans[get<1>(t)] = sum(ftree, get<3>(t)) - sum(ftree, get<2>(t) - 1);
		} else {
			add(ftree, get<3>(t), 1);
		}
	}
	
	for(int i = 1; i < q + 1; i++)
		cout << ans[i] << '\n';
}
