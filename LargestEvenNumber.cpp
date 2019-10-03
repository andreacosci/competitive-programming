#include <iostream>
#include <cstring>

inline int c2i(char* c) {
	return (int) *c - 48;
}

int main() {
	
	int testCase = 0;
	
	scanf("%d", &testCase);
	while(testCase-- > 0) {
		
		int minEven = -1, minOdd = -1;
		std::string input;
		std::cin >> input;
		
		int count[10];
		memset(count, 0, sizeof(int)*10);
		
		char b[input.length()];
		memset(b, 0, sizeof(char) * input.length());
		
		/*
		 * 	Do the counting sort, and find the minimum even(odd) number 
		 */ 
		
		for(char* c = &input[0]; *c != '\0'; c++) {
			count[c2i(c)]++;
		}
		
		if (count[0])
			minEven = 0;
		
		for(int i = 1; i < 10; i++) {
			if (minEven == -1 && count[i]) {
				if (i % 2 == 0)
					minEven = i;
				else if (minOdd == -1)
					minOdd	= i;
			}
			
			count[i] += count[i - 1];
		}
		
		int replace = (minEven != -1)? count[minEven] - 1 : count[minOdd] - 1;
		
		for(int i = input.length() - 1; i >= 0; --i) {
			b[count[c2i(&input[i])] - 1] = (char) input[i];
			count[c2i(&input[i])]--;
		}
		
		//Replace one minumum even(odd) occurence with a special char
		b[replace] = '\0';
		
		for(int i = input.length() - 1; i >= 0; --i)
			if (b[i] != '\0')
				std::cout << b[i];
			
		if (minEven != -1)
			std::cout << minEven << '\n';
		else
			std::cout << minOdd << '\n';
	}
	
	return 0;
}
