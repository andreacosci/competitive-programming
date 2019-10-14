#include <bits/stdc++.h>

using namespace std;

/**
* prime algorithm from : https://www.geeksforgeeks.org/primality-test-set-1-introduction-and-school-method/
*/
inline bool isPrime(int n) { 
	
    if (n <= 1) 
        return false; 
    if (n <= 3) 
        return true; 
  
    if (n % 2 == 0 || n % 3 == 0) 
        return false; 
  
    for (int i = 5; i * i <= n; i = i + 6) 
        if (n % i == 0 || n % (i + 2) == 0) 
            return false; 
  
    return true; 
	
}

inline int getPrev(int ind, vector<int>& array, vector<int>& prev) {
	if (prev[ind] == -1) {
		if (!array[ind]) {
			prev[ind] = 0;
			return 0;
		}
			
		prev[ind] = 1 + getPrev(array[ind] - 1, array, prev);
	} 
		
		return prev[ind];
}

inline void firing(vector<int>& array, vector<int>& prev) {
	int tot = 0;
	
	for(int i = array.size() - 1; i >= 0; --i) {
		if (array[i]) {
			if (isPrime(i + 1 + getPrev(i, array, prev))) {
				tot++;
			}
		}
	}
	
	cout << tot << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> array(n);
		vector<int> prev(n, -1);
		for(int& x : array)
			cin >> x;
			
		firing(array, prev);
	}
}
