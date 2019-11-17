#include <bits/stdc++.h>
     
using namespace std;
typedef long long ll;   
                 
void solve(string& a, string& b, int l1, int l2) {
	int table[l1 + 1][l2 + 1];
	for(int i = 0; i <= l1; i++) 
		memset(table[i], 0, sizeof(table[0]));
		
	for(int i = 0; i <= l1; i++) 
		table[i][0] = i;
		
	for(int i = 0; i <= l2; i++)
		table[0][i] = i;
		
	for(int i = 1; i <= l1; i++) {
		for(int j = 1; j <= l2; j++) {
			if (a[i - 1] == b[j - 1]) 
				table[i][j] = table[i-1][j-1];
			else {
				table[i][j] = min(
					min(table[i-1][j], table[i][j-1]),
					table[i-1][j-1]
				) + 1;
			}
		}
	}
		
	cout << table[l1][l2] <<'\n';
}
                                                                                                                   
int main() {
	ios_base::sync_with_stdio(false);
  cin.tie(0);
	int test; 
	cin >> test;
	while(test--) {
		int l1, l2;
		cin >> l1 >> l2;
		string a, b;
		cin >> a >> b;
		
		solve(a, b, l1, l2);
	}
	return 0;  	
}

