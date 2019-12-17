#include <bits/stdc++.h>
using namespace std;

bool dfs(int adj[26][26], int rec[], int vis[], int v, stack<int>& top) {
	if (!vis[v]) {
		vis[v] = 1;
		rec[v] = 1;
		for(int i = 0; i < 26; i++) {
			if (adj[v][i]) {
				if (!vis[i] && dfs(adj, rec, vis, i, top))
					return true;
				else if (rec[i]) 
					return true;
			}
			else
				continue;
		}
		
		top.push(v);
	}
	rec[v]= 0;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	
	int adj[26][26];
	memset(adj, 0, sizeof(adj));
		
	vector<string> name(n);
	for(auto& n : name)
		cin >> n;
	
	bool impossible = false;
	
	for(int i = 0, j = 1; j < n; i++, j++) {
		int k = 0;
		bool equal = false;
		
		while(name[i][k] == name[j][k]) {
			k++;
			if (k == name[i].length() || k == name[j].length()) {
				if (name[i].length() > name[j].length()) {
					cout << "Impossible";
					exit(0);
				}
				i++;
				j++;
				equal = true;
				break;
			}
		}
		
		if (!equal) {
			if (adj[ name[j][k] - 'a'][ name[i][k] - 'a']) {
				impossible = true;
				break;
			} else {
				adj[ name[i][k] - 'a'][ name[j][k] - 'a'] = 1;
			}
		}
	}
	
	int vis[26];
	int rec[26];
	stack<int> deg;
	
	memset(vis, 0, sizeof(vis));
	memset(rec, 0, sizeof(rec));
	
	if (impossible)
		cout << "Impossible";
	else
		for(int i = 0; i < 26; i++) {
				if (dfs(adj, rec, vis, i, deg)) {
					cout << "Impossible";
					exit(0);
				}
		}
	
	while(!deg.empty()) {
		cout << (char) (deg.top() + 'a');	
		deg.pop(); 
	}
	
	return 0;
}
