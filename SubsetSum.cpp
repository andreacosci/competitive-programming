#include <bits/stdc++.h>
     
using namespace std;
typedef long long ll;   
                 
void solve(vector<int>& a) {
	int n = a.size();
	ll sum = accumulate(a.begin(), a.end(), 0);
	
	if (sum % 2 != 0) {
	    cout << "NO\n";
	    return;   
	}
	
	sum /= 2;
	
	bool table[sum + 1][n + 1];	
	for(int i = 0; i < sizeof(table)/sizeof(table[0]); i++) 
		memset(table[i], 0, sizeof(table[0]));
		
	for(int i = 0; i<= n; i++)
		table[0][i] = true;
		
	for(int i = 1; i <= sum; i++) 
		for(int j = 1; j<= n; j++) {
			table[i][j] = table[i][j-1];
			if (i >= a[j-1])
				table[i][j] = table[i][j] || table[i - a[j-1]][j-1];	
	}
	
	if (table[sum][n])
		cout << "YES\n";
	else
		cout << "NO\n";
}
                                                                                                                   
int main() {
	ios_base::sync_with_stdio(false);
  cin.tie(0);
	int test; 
	cin >> test;
	while(test--) {
		int n; 
		cin >> n;
		vector<int> a(n);
		for(int& i : a) {
			cin >> i;
		}
		solve(a);
	}
	return 0;  	
}
