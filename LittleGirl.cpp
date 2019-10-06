#include <bits/stdc++.h>

using namespace std;

int main() {
	std::ios_base::sync_with_stdio(false);
	  
	int n, q;
	cin >> n;
	cin >> q;
	int64_t sum = 0;
	  
	auto array = vector<int64_t>(n);
	auto qArr  = vector<int64_t>(n + 1, 0);
	for(int i = 0; i < n; i++)
		cin >> array[i];
		
	for(int i = 0; i < q; i++) {
		int l = 0, r = 0;
		cin >> l;
		cin >> r;
		qArr[l - 1] += 1;
		qArr[r] -= 1;
	}
		
	for(int i = 1; i < n; i++)
		qArr[i] += qArr[i - 1];
		
	sort(qArr.begin(), qArr.end() - 1);
	sort(array.begin(), array.end());
	
	for(int i = 0; i < n; i++)
		sum += qArr[i] * array[i];
		
	std::cout << sum << '\n';
	
	return 0;
}
