#include <iostream>
#include <vector>
#include <stack>

/**
* I implemented the first solution using a deque then, when I watched the solution,
* I substituted the deque with the stack.
*/

inline void nextLarger(std::vector<long>& array) {
	std::stack<long> stack;

	for(auto it = array.rbegin(); it != array.rend(); ++it) {
		while(!stack.empty() && *it >= stack.top()) {
			stack.pop();	
		}
		
		long val = *it;
		
		if (!stack.empty())
			*it = stack.top();
		else
			*it = -1;
			
		stack.push(val);
	} 
	
	for(const long& x : array)
		std::cout << x << " ";
	
	std::cout << '\n';
}

int main() {
	
	int testCase = 0, length = 0;
	std::vector<long> array;
	
	scanf("%d", &testCase);
	while(testCase-- > 0) {
		
		scanf("%d", &length);
		array.reserve(length);
		
		for(int j = 0; j < length; ++j) {
			long tmp = 0;
			scanf("%ld", &tmp);
			array.push_back(tmp);
		}
		
		nextLarger(array);
		array.clear();
	}
	
	return 0;
}
