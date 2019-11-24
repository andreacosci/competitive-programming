#include <bits/stdc++.h>
     
using namespace std;
typedef long long ll;   
                 
void solve(vector<int>& a) {
	
	if (a.size() == 0) {
		cout << 0 <<'\n';
		return; 
	}
	
	int n = a.size();
	
	vector<int> inc(n,1);
	vector<int> dec(n,1);
	
	for(int i = 1; i < n; i++) {
	    for(int j = 0; j < i; j++) {
	        if (a[i] > a[j]) {
	            inc[i] = max(inc[i], inc[j] + 1);
	        }
	    }
	}
	
	for(int i = n-2; i >= 0; i--) {
	    for(int j = n -1; j > i; j--) {
	        if (a[i] > a[j]) {
	            dec[i] = max(dec[i], dec[j] + 1);
	        }
	    }
	}
	
	int mx = -1;
	for(int i = 0; i < n; i++) {
	    mx = max(mx, inc[i] + dec[i] - 1);
	}
	
	cout << mx << '\n'; 
	
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
    for(int& i : a) cin >> i;
    solve(a);
  }
  return 0;  	
 }

