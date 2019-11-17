#include <bits/stdc++.h>
     
using namespace std;
typedef long long ll;   
                 
void solve(vector<int>& a) {
	
	if (a.size() == 0) {
		cout << 0 <<'\n';
		return; 
	}
	
	int n = a.size();
	
	vector<int> inc(1);
	inc.reserve(n);
	
	inc[0] = a[0];
	
	for(int i = 1; i < n; i++) {
		auto it = lower_bound(inc.begin(), inc.end(), a[i]);
		
		if (it == inc.end())
			inc.push_back(a[i]);
		else
			*it = a[i];
	}
	
	cout << inc.size() << '\n';
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


