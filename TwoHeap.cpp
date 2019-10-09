#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	
	int n;
	vector<std::pair<int, int>> array;
	
	int heap[2] = {1, 0};
	int l_heap = 1;
	bool is_second = true;
	
	cin >> n;
	n *= 2;
	array.reserve(n);
	auto where = vector(n, 0);
	
	for(int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		array.push_back({tmp, i});
	}
	
	n/=2;
	sort(array.begin(), array.end());
	
	int last = get<0>(array.front());
	where[get<1>(array[0])] = 1;
	
	for(int i = 1; i < array.size(); ++i) {
		if (get<0>(array[i]) != last) { 
			is_second = true;
			heap[l_heap] += 1;
			where[get<1>(array[i])] = l_heap + 1;	
			last = get<0>(array[i]);
			l_heap = !l_heap;
			
		} else if (is_second) {
			is_second = false;
			heap[l_heap] += 1;
			where[get<1>(array[i])] = l_heap + 1;	
			last = get<0>(array[i]);
			l_heap = !l_heap;
		}
	}
		
	int comb = heap[0] * heap[1];
	cout << comb << '\n';
		
	for(int i = 0; i < array.size(); i++) {
		if (!where[i]) {
			where[i] = (heap[0]++ < n)?1:2;
		}
	}
	
	for(auto x : where)
		cout << x << " ";
		
	return 0;
}
