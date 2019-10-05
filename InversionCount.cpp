#include <bits/stdc++.h> 

inline int merge(std::vector<int>& array, int l, int m, int r) {
	int i, j, k;
	int n1 = m -l + 1;
	int n2 = r - m;
	int inv = 0;
	
	int L[n1 + 1], R[n2 + 1];
	
    for (i = 0; i < n1; i++) 
        L[i] = array[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = array[m + 1+ j]; 
        
    L[n1] = R[n2] = INT_MAX;
	i = j = 0;
	k = l;
	for(; k < r; k++) {
		if (L[i] <= R[j])
			array[k] = L[i++];
		else {
			array[k] = R[j++];
			inv += (m + 1) - i;
		}
	}
	
	return inv;
}

inline int inversionCount(std::vector<int>& array, int l, int r) {
	int inv = 0;
	
	if (l < r) {
		int m = l + (r - l)/2;
		inv = inversionCount(array, l, m);
		inv += inversionCount(array, m+1, r);
		inv += merge(array, l, m, r);
	}
	
	return inv;
}

int main() {
	int testCase;
	scanf("%d", &testCase);
	std::vector<int> array;
	
	for(;testCase-- > 0;) {
		int size = 0;
		scanf("%d", &size);
		array.reserve(size);
		
		for(;size-- > 0;) {
			int tmp = 0;
			scanf("%d", &tmp);
			array.push_back(tmp);
		}
		
		std::cout << inversionCount(array, 0, array.size()-1) << '\n';
		array.clear();
	}
}
