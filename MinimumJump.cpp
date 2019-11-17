#include <bits/stdc++.h>
     
using namespace std;
typedef long long ll;   
#define val second
#define weight first
                 
void solve(vector<int>& a) {
	int n = a.size();
	vector<ll> jump(n, INT_MAX);
	jump[0] = 0;
	
	for(int i = 1; i < n; i++) {
		for(int j = 0; j < i; j++) {
			if (a[j] + j >= i) {
				jump[i] = min(jump[i], jump[j] + 1);
			}
		}
	}
	
	if (jump[n-1] == INT_MAX)
		cout << -1 << '\n';
	else
		cout << jump[n-1] << '\n';
}
                                                                                                                   
int main() {
	ios_base::sync_with_stdio(false);
  cin.tie(0);
	int test; 
	cin >> test;
	while(test--) {
		int n; 
		cin >> n;
		vector<int> a(n);
		for(int& i : a) {
			cin >> i;
		}
			
		solve(a);
	}
	return 0;  	
}

