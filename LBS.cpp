#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n; 
        cin >> n;
        vector<int> a(n);
        for(int& i : a) cin >> i;
        vector<int> inc, dec;
        vector<int> ti(n), td(n);
        
        ti[0] = 0;
        inc.push_back(a[0]);

		for(int i = 1; i < n; i++) {
			auto it = lower_bound(inc.begin(), inc.end(), a[i]);
			
			if (it == inc.end())
				inc.push_back(a[i]), ti[i] = inc.size() - 1;
			else {
				*it = a[i];
				if (it == a.begin()) ti[i] = 0;
				else ti[i] = it - inc.begin();
			}	
		}
		
		reverse(a.begin(), a.end());
        td[0] = 0;
        dec.push_back(a[0]);
		
		for(int i = 1; i < n; i++) {
			auto it = lower_bound(dec.begin(), dec.end(), a[i]);
			
			if (it == dec.end())
				dec.push_back(a[i]), td[i] = dec.size() - 1;
			else {
				*it = a[i];
				if (it == a.begin()) td[i] = 0;
				else td[i] =  it - dec.begin();
			}	
		}
		
		reverse(td.begin(), td.end());
        
        int ans = 0;
        for(int i = 0; i < n; i++)
            ans = max(ans, ti[i] + td[i] + 1);
            
        cout << ans << '\n';
        
    }
	return 0;
}
