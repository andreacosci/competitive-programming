#include <bits/stdc++.h> 

inline void perform_query(std::vector<int>& prefix, int l, int r) {
	int p_l = prefix[l-1];
	int p_r = prefix[r-1];
	std::cout << p_r - p_l << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::string inputString;
	std::cin >> inputString;
	
	int queries;
	std::cin >> queries;
	
	std::vector<int> prefix(inputString.size());
	prefix[0] = 0;
	
	for(int i = 1; i < inputString.size(); ++i) {
		prefix[i] = (inputString[i] == inputString[i-1])? 1 + prefix[i-1] : 0 + prefix[i-1];
	}

	for(;queries-- > 0;) {
		int l = 0, r = 0;
		std::cin >> l;
		std::cin >> r;
		perform_query(prefix, l, r);
		inputString.clear();
	}
}
