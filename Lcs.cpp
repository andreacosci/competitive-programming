#include <bits/stdc++.h>
     
using namespace std;
typedef long long ll;   
                                                                                                                   
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
		
		assert(l1 > 0 && l2 > 0);
		int table[l1 + 1][l2 + 1];
		for(int i = 0; i <= l1; i++) {
			memset(table[i], 0, sizeof(table[0]));
		}
		
		for(int i = 1; i <= l1; i++) 
			for(int j = 1; j <= l2; j++) 
				table[i][j] = (a[i-1] == b[j-1])?table[i-1][j-1] + 1:max(table[i][j-1], table[i-1][j]);

		cout << table[l1][l2] << '\n';
	}
    
	return 0;  	
}
