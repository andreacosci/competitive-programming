#include <iostream>

using namespace std;

int main() {
	int testCase = 0, length = 0;
	scanf("%d", &testCase);
	
	for(;testCase > 0; testCase--) {
	    scanf("%d", &length);
	    
	    size_t sum = (length*(length + 1)) / 2;
	    
	    for(int i = 1; i < length; ++i) {
			int tmp = 0;
			scanf("%d", &tmp);
			
			sum -= tmp;
		}
		
		std::cout << sum << '\n';
	}
	return 0;
}
