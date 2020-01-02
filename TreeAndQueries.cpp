/*
	solution adapted from vjudge's solution on
	Codeforces
*/

#include<bits/stdc++.h>
using namespace std;

static int B; 
#define N 200006

typedef struct query {
	int l,
		r,
		k,
		id;	
} Query;

bool cmp(const Query&  a, const Query&  b){
	return a.r/B < b.r/B || a.r/B == b.r/B && a.l < b.l;
}
	
int n, m, cnt;
int ans[N], sum[N], a[N], c[N], ed[N], beg[N], num[N];
vector<int> adj[N];
Query q[N];

inline void dfs(const int& u, const int& p) {
	c[beg[u] = ++cnt] = a[u];
	for(int i=0; i < adj[u].size(); i++)
		if(adj[u][i] != p)
			dfs(adj[u][i],u);
	ed[u] = cnt;		
}
 
int main() {
	scanf("%d%d", &n, &m);
	B = sqrt(n);
			
	for(int i = 1; i <= n; i++)
		scanf("%d", a + i);
			
	for(int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	dfs(1,0);
		
	for(int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		q[i] = (Query) {beg[u], ed[u], v, i};
	}
		
	sort(q + 1, q + m + 1, cmp);
	sum[0] = n;
	
	for(int i=1, l=1, r=0; i <= m; i++) {
		while(r<q[i].r)++sum[++num[c[++r]]];
		while(r>q[i].r)--sum[num[c[r--]]--];
		while(l>q[i].l)++sum[++num[c[--l]]];
		while(l<q[i].l)--sum[num[c[l++]]--];
		ans[q[i].id] = sum[q[i].k];
	}
		
	for(int i = 1; i <= m; i++)
		printf("%d\n", ans[i]);
			
	return 0;
}
