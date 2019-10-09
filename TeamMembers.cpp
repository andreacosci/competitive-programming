#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;

	n*=2;
	n--;
	vector<tuple<int, int, int>> array;
	auto with = vector<int>(n + 1, 0);
	array.reserve(n);
	
	for(int i = 0; i < n; i++) 
		for(int j = 0; j < i + 1; j++)
	{
		int tmp;
		cin >> tmp;
		array.push_back({-tmp, i + 1, j});
	}
	
	sort(array.begin(), array.end());
	
	for(int i = 0; i < array.size(); i++) {
		if (!with[get<1>(array[i])] && !with[get<2>(array[i])]) {
			with[get<1>(array[i])] = get<2>(array[i]) + 1;
			with[get<2>(array[i])] = get<1>(array[i]) + 1;
		}
	}
	
	for(auto x : with)
		cout << x << " ";
	
	
}
