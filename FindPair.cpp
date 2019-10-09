#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	
	uint64_t size, k = 0;
	std::cin >> size;
	std::cin >> k;
	
	std::vector<int64_t> array;
	array.reserve(size);
	
	for(int i = size; i >0; --i) {
		int64_t tmp;
		std::cin >> tmp;
		array.push_back(tmp);
	}
	
	std::sort(array.begin(), array.end());
	uint64_t i = (k-1)/size;
	int64_t first = array[i];
	
	uint64_t l; //1 1 2
	for(l = 0; l < size; l++)
		if(array[l] == first) break;
   
	uint64_t r = std::count(array.begin(), array.end(), first);
	int64_t second = array[((k-1)-l*size)/r];
  
	std::cout << first << " " << second << '\n';
	
	return 0;
}
