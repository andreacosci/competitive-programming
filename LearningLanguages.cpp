#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& adj, vector<bool>& visited, int v) {
	if (!visited[v]) {
		visited[v] = true;
		for(int i = 0; i < (int) visited.size(); i++) {
			if (adj[v][i]) dfs(adj, visited, i);
		}
	}	
}

int main() {
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	
	vector<bool> visited(n + m, false);
	vector<vector<int>> adj(n + m);
	for(auto& x : adj)
		x = vector<int>(n + m, 0);
		 
	bool zeros = true;
	for(int i = 0; i < n; i++) {
		int lk;
		cin >> lk;
			
		while(lk--) {
			zeros = false;
			int k;
			cin >> k;
			adj[i][k + n - 1] = 1;
			adj[k + n - 1][i] = 1;
		}
	}
	
	int count = -1;
	for(int i = 0; i < n; i++) {
		if (!visited[i]) {
			dfs(adj, visited, i);
			count++;
		}
	}
	cout << count + (zeros);
	return 0;
}
