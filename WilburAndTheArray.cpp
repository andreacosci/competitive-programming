#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> b(n);
	for(int& i : b) 
		cin >> i;
		
	int last = 0;
	long long tot  = 0;
	for(int i = 0; i < n; i++) {
		tot += abs(b[i] - last);
		last = b[i];
	}
	
	cout << tot;
}
