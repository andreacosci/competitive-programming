#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	
	int n = s.length();
	vector<char> res;
	res.reserve(n);
	
	res.push_back(s[n-1]);
	
	for(int i = n - 2; i >= 0; i--) {
		if (res.back() <= s[i]) {
			res.push_back(s[i]);
		}
	}
	
	for(auto it = res.rbegin(); it != res.rend(); it++)
		cout << *it;
		
	return 0;
}
