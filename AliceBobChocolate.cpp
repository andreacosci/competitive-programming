#include <bits/stdc++.h> 

inline void bar_eated(std::vector<int>& array) {
	int alice = 0;
	int leftSum = array.front();
	int rightSum = array.back();
	
	int i = 0, j = array.size() - 1;
	
	while(i <= j) {
		if (leftSum <= rightSum) {
			leftSum += array[++i];
			alice++;
		}
		else
			rightSum += array[--j];
	}
	
	std::cout << alice << " " << array.size() - alice;
	
}

int main() {
	
	int barLength;
	scanf("%d", &barLength);
	
	std::vector<int> array;
	array.reserve(barLength);
	
	for(;barLength-- > 0;) {
		int tmp = 0;
		scanf("%d", &tmp);
		array.push_back(tmp);
	}
	
	bar_eated(array);
	
	return 0;
}

