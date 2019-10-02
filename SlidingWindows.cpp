#include <iostream>
#include <vector>
#include <deque>

/**
 * This uses solution described in this lecture:
 * https://github.com/rossanoventurini/CompetitiveProgramming/blob/master/notes/lecture2.pdf
 */ 

inline void slidingWindows(const std::vector<int>& array, int k) {
	std::deque<int> Q;
	
	for(int i = 0; i < array.size(); ++i) {
		while(!Q.empty() && Q.front() <= i - k)
			Q.pop_front();
			
		while(!Q.empty() && array[i] >= array[Q.back()])
			Q.pop_back();
			
		Q.push_back(i);
		
		if ( i >= k - 1)
			std::cout << array[Q.front()] << " ";
	}
	
	
	std::cout << '\n';
	
} 

int main() {
	
	int testCase = 0, length = 0, k = 0;
	std::vector<int> array;
	
	scanf("%d", &testCase);
	while(testCase-- > 0) {
		
		scanf("%d", &length);
		array.reserve(length);
		
		scanf("%d", &k);
		
		for(int j = 0; j < length; ++j) {
			int tmp = 0;
			scanf("%d", &tmp);
			array.push_back(tmp);
		}
		
		slidingWindows(array, k);
		array.clear();
	}
	
	return 0;
}
