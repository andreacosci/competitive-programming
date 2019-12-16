#include <bits/stdc++.h>
using namespace std;

void dfs(int i, int j, vector<string>& mat, vector<vector<int>>& vis, int n, int m) {
	if (i < 0 || j < 0 || i >= n || j >= m || vis[i][j] || mat[i][j] != 'X')
		return;
	else {
		vis[i][j] = 1;
		dfs(i-1, j, mat, vis, n, m);
		dfs(i, j-1, mat, vis, n, m);
		dfs(i+1, j, mat, vis, n, m);
		dfs(i, j+1, mat, vis, n, m);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	int t; 
	cin >> t;
	
	while(t--) {
		int n, m;
		cin >> n >> m;
		vector<string> mat(n);
		vector<vector<int>> vis(n);
		for(int i = 0; i < n; i++) {
			cin >> mat[i];
			vis[i] = vector<int>(m, 0);
		}
		
		int counter = 0;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				if (mat[i][j] == 'X' && !vis[i][j]) {
					counter++;
					dfs(i, j, mat, vis, n, m);				
				}
		
		cout << counter << '\n';
	}
	return 0;
}
