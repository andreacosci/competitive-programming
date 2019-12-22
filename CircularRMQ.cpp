#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;

class Problem {
public:
	
	vector<ll> seg;
	vector<ll> lazy;
	const ll INF = 1e18;
	
	void setup() {
		cin >> n;
		seg = vector<ll>(16*n, 0);
		lazy = vector<ll>(16*n, 0);
		
		for(int i = 0; i < n; i++) {
			int tmp;
			scanf("%d", &tmp);
			add(i, i+1, tmp);
		}
	}
	
	void shift(int id) {
		seg[2*id] 	 += lazy[id];
		seg[2*id+1]  += lazy[id];
		lazy[2*id]	 += lazy[id];
		lazy[2*id+1] += lazy[id];
		lazy[id]	 =  0;
	}
	
	ll get(int ql, int qr, int l=0, int r=n, int id=1) {
		if(qr <= ql) 
			return min(get(ql, n), get(0, qr));
		if(r <= ql || qr <= l) 
			return INF;
		if(ql <= l && r <= qr) 
			return seg[id];
		int mid = (l+r)/2;
		shift(id);
		return min( get(ql, qr, mid, r, 2*id+1), get(ql, qr, l, mid, 2*id));
	}
	
	void add(int ql, int qr, ll val, int l=0, int r=n, int id=1) {
		if (qr <= ql) {
			add(ql, n, val) , add(0, qr, val);
			return;
		}
		if(r <= ql || qr<=l ) return;
		if(ql<=l && r<=qr) {
			seg[id] += val;
			lazy[id] += val;
			return;
		}
		int mid = (l+r)/2;
		shift(id);
		add(ql, qr, val, l, mid, 2*id);
		add(ql, qr, val, mid, r, 2*id+1);
		seg[id] = min(seg[2*id],seg[2*id+1]);
		return;
	}
};

int main()
{
	Problem problem = Problem();
	problem.setup();
	
	int m;
	cin >> m;
	
	while(m--){ 
		int l,r; char c;
		scanf("%d %d%c",&l,&r,&c);
		r++;
		if(c == ' '){
			ll val; 
			cin >> val;
			problem.add(l, r, val);
		} else
			cout << problem.get(l, r) << '\n';
	}
	return 0;
}
