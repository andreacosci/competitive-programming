#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	string n;
	cin >> n;
	int res[n.size() + 1];
	res[0] = 1;
	
	for(int i = 0; i < (int) n.size(); i++) {
		res[i + 1] = res[i] && n[i] == '1';
		if (i != 0)
			res[i+1] = res[i+1] || (res[i-1] && n[i-1]=='1' && n[i] == '4');
		if (i > 1)
			res[i+1] = res[i+1] || (res[i-2] && n[i-2]=='1' && n[i-1] == '4' && n[i] == '4');
	}
	
	if (res[n.size()])
		cout << "YES";
	else
		cout << "NO";
}
