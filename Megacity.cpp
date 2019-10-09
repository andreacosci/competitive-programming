#include <bits/stdc++.h>

inline void binary_search(std::vector<std::pair<double, int>>& cities, int pplNeed) {
	if (pplNeed <= 0)
		std::cout << "-1" << '\n';
		
	double last = -1.0;
	int l = 0, r = cities.size() - 1;
	
	while(l <= r) {
		int m = l + (r - l) / 2;
		int val = -std::get<1>(cities[m]);
		
		if (val >= pplNeed) {
			last = std::get<0>(cities[m]);
			r = m - 1;
		} else 
		if (val < pplNeed) {
			l = m + 1;
		}
	}
	
	if (last != -1)
		printf("%.7f\n", last);
	else
		std::cout << "-1" << '\n';
		
}

int main() {
	std::ios_base::sync_with_stdio(false);
	int points; int ppl;
	std::cin >> points;
	std::cin >> ppl;
	
	std::vector<std::pair<double, int>> cities;
	cities.reserve(points);
	
	while(points-- > 0) {
		int x, y, a;
		std::cin >> x;
		std::cin >> y;
		std::cin >> a;
		
		/* negative number of habitants for sorting.
		In case of same distance, the pair's comparison function will put first 
		the city with highest number of people, no need to write a custom
		lambda compare function. */
		cities.push_back({sqrt(x*x + y*y), -a});
	}
	
	std::sort(cities.begin(), cities.end());
	for(int i = 1; i < cities.size(); i++) {
		std::get<1>(cities[i]) += std::get<1>(cities[i - 1]);
	}
	
	binary_search(cities, 1000000 - ppl);
}
