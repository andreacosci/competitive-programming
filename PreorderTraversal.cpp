#include <iostream>
#include <stack>
#include <vector>
#include <limits.h>
using namespace std;

/**
 * Solution: https://www.geeksforgeeks.org/check-if-a-given-array-can-represent-preorder-traversal-of-binary-search-tree/
 */
 
inline int isPreorder(vector<int>& array) {
    stack<int> s;
    int root = INT_MIN;
    
    for(const int& v : array) {
        if (v < root)
            return 0;
            
        while(!s.empty() && s.top() < v) {
            root = s.top();
            s.pop();
        }
        
        s.push(v);
    }
    
    return 1;
}

int main() {
    int testCase = 0;
    scanf("%d", &testCase);
    vector<int> array;
    
    while(testCase-- > 0) {
        int N = 0;
        scanf("%d", &N);
        
        array.reserve(N);
        for(int i = 0; i < N; ++i) {
            int tmp = 0;
            scanf("%d", &tmp);
            array.push_back(tmp);
        }
        
        printf("%d\n", isPreorder(array));
        array.clear();
    }
	return 0;
}
