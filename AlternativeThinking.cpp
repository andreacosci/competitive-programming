#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int n; 
	cin >> n;
	string s;
	cin >> s;
	
	int dif = 0, eq = 0;
	for(int i = 0; i < n-1; i++) {
		if (s[i] != s[i+1]) dif++;
		else 
			eq++;
	}
	
	cout << dif + min(eq, 2) + 1;
	return 0;
}
