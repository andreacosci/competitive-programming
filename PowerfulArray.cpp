#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
typedef struct {
	int l;
	int r;
	int id;
} Query;
 
class Mo {
public:
	ll BLOCK;
	
	Mo(ll n) : BLOCK{ (ll) sqrt(n)} {}
	
	void sort(Query q[], const ll& m) {
		std::sort(q, q + m, [this] (const Query& a, const Query& b) {
			if (a.l/BLOCK != b.l/BLOCK)
				return a.l/BLOCK < b.l/BLOCK;
		
			return a.r < b.r;
		});
	}
};
 
void add(int x, ll& tans, vector<ll>& cnt, ll a[]) {
	tans+=1ll*(2*cnt[a[x]]+1)*a[x];
	++cnt[a[x]];
}
void del(int x, ll& tans, vector<ll>& cnt, ll a[]) {
	tans-=1ll*(2*cnt[a[x]]-1)*a[x];
	--cnt[a[x]];
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	ll n, m;
	cin >> n >> m;
	Mo mo = Mo(n);
	
	ll arr[n];
	ll ans[m];
	vector<ll> cnt(10e6 + 1, 0);
	Query query[m];
	
	for(int i = 0; i < n; i++) cin >> arr[i];
	for(int i = 0; i < m; i++) {
		cin >> query[i].l;
		cin >> query[i].r;
		--query[i].l;
		--query[i].r;
		query[i].id = i;
	}
	
	mo.sort(query, m);
	ll r = -1, l = 0;
	ll tans = 0;
	for(int i = 0; i < m; i++) {
		while(r < query[i].r) add(++r, tans, cnt, arr);
		while(r > query[i].r) del(r--, tans, cnt, arr);
		while(l < query[i].l) del(l++, tans, cnt, arr);
		while(l > query[i].l) add(--l, tans, cnt, arr);
		ans[query[i].id] = tans;
	}
	
	for(const ll& a : ans)
		cout << a << '\n';
		
	return 0;
}
