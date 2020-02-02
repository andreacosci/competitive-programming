#include<bits/stdc++.h>
using namespace std;
 
void add(vector<int>& ftree, int i, int v) {
	for(++i; i < ftree.size(); i += i&-i)
		ftree[i] += v;
}

int sum(vector<int>& ftree, int i) {
	int sum = 0;
	
	for(i; i > 0; i&=i-1) {
		sum += ftree[i];
	}
	
	return sum;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int n;
    cin >> n;
    
    vector<int> a(n);
    vector<int> tot(n);
    vector<int> cnt(n + 1, 0), rem(n + 1, 0);
    vector<int> ftree(n + 2, 0);
    
    int sz = 0;
    
    for (int i = 0; i < n; i++) 
		cin >> a[i], tot[i] = a[i];
 
    sort(tot.begin(), tot.end());
    sz = unique(tot.begin(), tot.end()) - tot.begin();
 
    for (int i = 0; i < n; i ++) 
		a[i] = lower_bound(tot.begin(), tot.end(), a[i]) - tot.begin();
 
    for (int i = n - 1; i >= 0; i --)
    {
        cnt[a[i]]++;
        add(ftree, cnt[a[i]], 1);
 
        rem[i] = cnt[a[i]];
    }
 
    cnt = vector<int>(n + 1, 0);
    long long ans = 0;
    for (int i = 0; i < n; i ++)
    {
        add(ftree, rem[i], -1);
        
        cnt[a[i]] ++;
        ans += sum(ftree, cnt[a[i]]) - sum(ftree, 1);
    }
 
    cout << ans << '\n';
    return 0;
}
