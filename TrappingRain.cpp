#include <iostream>
#include <vector>

inline int min(int& a, int& b) {
	return (a<=b)?a:b;
}

inline void trappingRain(const std::vector<int>& array) {
	int maxL, maxR;
	
	maxL = array.front();
	maxR = array.back();

	std::vector<std::pair<int, int>> maxMinArray(array.size());
	
	for(int i = 1; i < array.size(); ++i) {
		if (array[i] > maxL) {
			maxL = std::get<0>(maxMinArray[i]) = array[i];
		} else {
			std::get<0>(maxMinArray[i]) = maxL;
		}
		
		std::get<1>(maxMinArray[array.size() - i]) = maxR;
		if (array[array.size() - i] > maxR) {
			maxR = array[array.size() - i];
		}
	}
	
	size_t sum = 0;
	for(int i = 1; i < array.size() - 1; ++i) {
		int tmp = min(std::get<0>(maxMinArray[i]), std::get<1>(maxMinArray[i])) - array[i];
		
		if (tmp > 0)
		sum += tmp;
	}
	
	std::cout << sum << '\n';
} 

int main() {
	
	int testCase = 0, length = 0;
	std::vector<int> array;
	
	scanf("%d", &testCase);
	while(testCase-- > 0) {
		
		scanf("%d", &length);
		array.reserve(length);
		
		for(int j = 0; j < length; ++j) {
			int tmp = 0;
			scanf("%d", &tmp);
			array.push_back(tmp);
		}
		
		trappingRain(array);
		array.clear();
	}
	
	return 0;
}
