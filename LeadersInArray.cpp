#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * this solution uses the given array to store the
 * leaders found. Thus we can achieve constant space
 */
inline void printLeaders(vector<int> & array) {
	int max = array.back();
	//j is the next empty slot for storing leaders
	int j = array.size() - 1;
	
	array[j--] = max;
	
    for (int i = j; i >= 0; --i) {
        if (array[i] >= max) {
            max = array[i];
            //We can use previous position to store leaders
            array[j--] = max;
        }
	}	
	
	//If we iterate over j + 1 to N we will print all the leaders found
	for(j = j + 1; j < array.size(); ++j)
		printf("%d ", array[j]);
	
	std::cout << '\n';
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
		
		printLeaders(array);
		array.clear();
	}
	return 0;
}
