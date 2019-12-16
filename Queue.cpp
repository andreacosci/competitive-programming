#include <bits/stdc++.h>
using namespace std;

struct person {
	person() : a{0}, h{1}, name{string("")} {}
	int a;
	int h;
	string name;
};

int compare(person a, person b) {
	return a.a < b.a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n; 
	cin >> n;
	vector<person> queue(n);
	for(auto& p : queue) {
		cin >> p.name;
		cin >> p.a;
	}
	
	sort(queue.begin(), queue.end(), compare);
	for(int i = 0; i < n; i++) {
		person& p = queue[i];
		if (p.a > i) {
			cout << -1 << '\n';
			exit(0);
		}
		else {
			p.h = i + 2 - p.a;
			for(int j = 0; j < i; j++) {
				if (queue[j].h >= p.h)
					queue[j].h++;
			}
		}
	}
	
	for(auto p : queue)
		cout << p.name << " " << p.h << '\n';
		
	return 0;
}
