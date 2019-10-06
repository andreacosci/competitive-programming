#include <bits/stdc++.h>

/**
 * 	A slightly different version of this solution:
 * 	https://github.com/rossanoventurini/CompetitiveProgramming/blob/master/code/NumberWays.cpp
 */ 

using namespace std;

int main() {
  std::ios_base::sync_with_stdio(false);
  
  int n;
  cin >> n;
  int64_t sum = 0;
  
  vector<int64_t> array(n);
  for(int i = 0; i < n; i++) {
	  cin >> array[i];
  }
  
  auto c = vector<int64_t>(n, 0);

  for(const int64_t& x : array)
    sum += x;
  
  if(sum % 3 != 0) {
    cout << "0\n";
    return 0;
  }
  
  sum = sum/3;
  
  int64_t k = array[n - 1];
  c[n - 1] = (k == sum)?1:0;
  
  for(int i = n-2; i >= 0; --i) {
    k += array[i];
    
    if(k == sum)
      c[i] = 1;
      
     c[i] += c[i+1];
  }

  k = 0;  
  int64_t ways = 0; 
  for(int i = 0; i < n-2; ++i) {
    k += array[i];
    if(k == sum) 
		ways += c[i+2];
  }
  
  cout << ways << endl;
  
  return 0;
}
