#include <bits/stdc++.h>
using namespace std;

void solve(string& s) {
    int n = s.length();

    int table[n+1][n+1];
    for(int i = 0; i < n + 1; i++)
        memset(table[i], 0, sizeof(table[0]));
        
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if (s[i - 1] == s[n - j]) {
                table[i][j] = 1 + table[i-1][j-1];
            } else {
                table[i][j] = max(table[i-1][j], table[i][j-1]);
            }
        }
    }
    
    cout << table[n][n] << '\n';
}

int main() {
	int test;
	cin >> test;
	
	while(test--){
	    string s; 
	    cin >> s;
	    solve(s);
	} 

	return 0;
}
