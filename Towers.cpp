#include <bits/stdc++.h> 

int main() {
	int numBars;
	std::vector<int> array;
	
	scanf("%d", &numBars);
	array.reserve(numBars);
	
	for(; numBars-- > 0;) {
		int tmp = 0;
		scanf("%d", &tmp);
		array.push_back(tmp);
	}
	
	std::sort(array.begin(), array.end());
	
	int last = array.front();
	int longest = 1;
	int length = 1;
	int towers = 1;
	
	for(auto it = array.begin() + 1; it != array.end(); ++it) {
		if (*it > last) {
			last = *it;
			towers++;
			length = 1;
		} else 
			longest = (++length > longest)? length : longest;
	}
	
	std::cout << longest << " " << towers;
	
	return 0;
}
