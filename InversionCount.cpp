#include <bits/stdc++.h> 

inline long merge(std::vector<long>& array, long l, long m, long r) {
	long i, j, k;
	long n1 = m -l + 1;
	long n2 = r - m;
	long inv = 0;
	
	long L[n1 + 1], R[n2 + 1];
	
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

inline long inversionCount(std::vector<long>& array, long l, long r) {
	long inv = 0;
	
	if (l < r) {
		long m = l + (r - l)/2;
		inv = inversionCount(array, l, m);
		inv += inversionCount(array, m+1, r);
		inv += merge(array, l, m, r);
	}
	
	return inv;
}

int main() {
	int testCase;
	scanf("%d", &testCase);
	std::vector<long> array;
	
	for(;testCase-- > 0;) {
		long size = 0;
		scanf("%lo", &size);
		array.reserve(size);
		
		for(;size-- > 0;) {
			long tmp = 0;
			scanf("%lo", &tmp);
			array.push_back(tmp);
		}
		
		std::cout << inversionCount(array, 0, array.size()-1) << '\n';
		array.clear();
	}
}
