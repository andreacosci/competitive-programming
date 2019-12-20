#include <bits/stdc++.h>
using namespace std;
 
int solve(vector<vector<int>>& adj, vector<array<int, 2>>& dp, vector<array<bool, 2>>& visited, int u, int taken, int parent)
{
    if(visited[u][taken] == 1)
        return dp[u][taken];
        
    visited[u][taken] = 1;
    int ans = 0;
    
    for(auto it = adj[u].begin(); it != adj[u].end(); it++) {
    	if (*it != parent) {
		
		    if (taken)
				ans += min(solve(adj, dp, visited, *it , 1, u), solve(adj, dp, visited, *it, 0, u));
			else
				ans += solve(adj, dp, visited, *it, 1, u);
		}
	}
	
    ans += taken;
    dp[u][taken] = ans;
    return ans;
}

int main()
{
    int n;
    scanf("%d", &n);
	
	vector<array<bool,2>>   visited(n + 1); 
	vector<array<int, 2>> 	dp(n + 1);
	vector<vector<int>> 	adj(n + 1);
	
	for(int i = 0; i <= n; i++) {
		visited[i][0] = false;
		visited[i][1] = false;
		dp[i][0] = 0;
		dp[i][1] = 0;
	}
	
	for(int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	printf("%d", min(solve(adj, dp, visited, 1, 1, -1), solve(adj, dp, visited, 1, 0, -1)));

    return 0;
}
