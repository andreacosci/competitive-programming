#include <bits/stdc++.h>
     
using namespace std;
typedef long long ll;   
#define val second
#define weight first
                                                                                                                   
int main() {
	ios_base::sync_with_stdio(false);
  cin.tie(0);
	int s, n;
	cin >> s >> n;
	vector<pair<int, int>> items(n);
	
	for(auto& i : items) {
		cin >> i.weight >> i.val;
	}
	
	int table[n+1][s+1];
	for(int i = 0; i <= n; i++) 
		memset(table[i], 0, sizeof(table[0]));
		
	for(int i = 1; i <= n; i++) 
		for(int j = 1; j <= s; j++) {
			if (items[i-1].weight <= j) 
				table[i][j] = max(
					items[i-1].val + table[i-1][j - items[i-1].weight],
					table[i-1][j]
				);
			else
				table[i][j] = table[i-1][j];
	}
	
	cout << table[n][s] << '\n';
	return 0;  	
}
