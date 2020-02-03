#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MOD 1000000007ll

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
    int n;
    cin >> n;
    int size, comps, dfstime;
    vector<int> cost(n), dtime(n, -1), stack(n, 0), comp(n, 0), low(n, 0);
    vector<bool> instack(n, false);
    vector<vector<int>> edge(n);
    
    for(int & c : cost) cin >> c;
    
    int m;
    cin >> m;
    
	for(int i = 0; i < n; i++)
		edge[i] = vector<int>();
    
    while(m--){
        int u,v;
        cin >> u >> v;
        u--,v--;
        edge[u].push_back(v);
    }
    
    std::function<void(int)> tarjan = [&] (int u) {
		low[u] = dtime[u] = ++dfstime;
	    stack[size++] = u;
	    instack[u] = true;
	 
	    for(int i = 0; i < edge[u].size(); i++) {
	        int v=edge[u][i];
	        if(dtime[v]==-1) tarjan(v), low[u] = min(low[u], low[v]);
	        else if(instack[v]) low[u] = min(low[u], dtime[v]);
	    }
	 
	    if(dtime[u] == low[u]){
	        comps++;
	        int v=-1;
	        do{
	            v = stack[--size];
	            instack[v] = false;
	            comp[v] = comps;
	        } while(u != v);
	    }	
	};
	
    comps = dfstime = size = 0;
    
    for(int i = 0; i < n; i++)
		if(dtime[i]==-1) tarjan(i);
		
	vector<int>  mini(comps + 1), cnt(comps + 1);
	
    for(int i=1; i <= comps; i++) mini[i]=INT_MAX;
    for(int i = 0; i < n; i++){
        int c = comp[i];
        int w = cost[i];
        if (mini[c] > w) mini[c]=w, cnt[c]=1;
        else if(mini[c]==w) cnt[c]++;
    }
    
    ll a=0, b=1;
    for(int i=1; i <= comps; i++){
        a += mini[i];
        b *= 1ll * (cnt[i]);
        b %= MOD;
    }
    
    cout << a << " " << b << '\n';
    return 0;
}
