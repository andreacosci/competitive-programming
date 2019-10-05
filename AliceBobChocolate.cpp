#include <bits/stdc++.h> 

inline void bar_eated(std::vector<int>& array) {
	
	if (array.size() == 1) {
		std::cout << "1 0";
		return;
	}
	
	int alice = 0;
	
	std::vector<int> prefix;
	std::vector<int> sufx;
	
	sufx.reserve(array.size());
	prefix.reserve(array.size());
	
	sufx.push_back(array.back());
	prefix.push_back(array.front());
	
	for(int i = 1, j = array.size() - 2; j >= 0; --j, ++i) {
		prefix.push_back(prefix[i - 1] + array[i]);
		sufx.push_back(sufx.back() + array[j]);
	}
	
	auto a = prefix.begin();
	auto b = sufx.rbegin();
	
	while(*a <= *b) {
		alice++; a++; b++;
	}
	
	std::cout << alice << " " << array.size() - alice;
	
}

int main() {
	
	int barLength;
	scanf("%d", &barLength);
	
	std::vector<int> array;
	array.reserve(barLength);
	
	for(;barLength-- > 0;) {
		int tmp = 0;
		scanf("%d", &tmp);
		array.push_back(tmp);
	}
	
	bar_eated(array);
	
	return 0;
}
