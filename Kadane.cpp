#include <vector>
#include <iostream>

using namespace std;

inline void kadane(const vector<int> & array) {
	
	int sum = array.front();
	int max_sum = sum;
	
	for(auto it = array.begin() + 1; it != array.end(); ++it) {
		sum = sum*(sum > 0) + *it;
		
		if (sum > max_sum)
			max_sum = sum;
	}
	
	std::cout << max_sum << '\n';
}

int main() {
	
	int testCase = 0, length = 0;

    vector<int> array;	 
	scanf("%d", &testCase);
	
	for(;testCase > 0; testCase--) {
		
	    scanf("%d", &length);
	    array.reserve(length);
	    
	    for(int i = 0; i < length; ++i) {
			int tmp = 0;
			scanf("%d", &tmp);
			array.push_back(tmp);
		}
		
		kadane(array);
		array.clear();
		
	}
	
	return 0;
}
