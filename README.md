# competitive-programming
Competitive Programming and Contests Homeworks collection

## Leaders in the array
The algorithm will scan the array backwards. Every time it meets an item bigger than the last leader, will save him and update the last leader. To achieve constant extra memory, the algorithm will store each leader in the last free previous visited position. In fact at the k-th iteration we can have found at most (k - 1) leaders.

*Time complexity:* **O(n)**
*Space Complexity:* **O(n)**

[Source Code](https://github.com/andreacosci/competitive-programming/blob/master/LeadersInArray.cpp)

## Kadane's Algorithm
We set a variable sum and a variable maximum to the first element of the array, then we scan from the second element to the end doing the following steps: 
1) if sum is negative we set the sum to the element consider in the current iteration. Otherwise we add this element to the sum.
2) if this sum is greater than the previous maximum, we update it.

*Time complexity:* **O(n)**
*Space Complexity:* **O(n)**

[Source Code](https://github.com/andreacosci/competitive-programming/blob/master/Kadane.cpp)

## Missing Number in Array
We use gauss formula to calculate the first n-natural number sum. Then we subtract each element to our value. In the end the missing element will remain in the variable.

*Time complexity:* **O(n)**
*Space Complexity:* **O(1)**

[Source Code](https://github.com/andreacosci/competitive-programming/blob/master/MissingNumber.cpp)

## Trapping Rain Water
We compute and store the maximum element on the left ad on the right of each element. Then the solution locally will be the minimum between the two maximum minus the value of the consider element.

*Time complexity:* **O(n)**
*Space Complexity:* **O(n)**

[Source Code](https://github.com/andreacosci/competitive-programming/blob/master/TrappingRain.cpp)

## Sliding Window Maximum
We describe the window as a queue. We start with the window in position <-k, -1> then we move by one each iteration and we do the following step:
1) Remove elements no longer in the window
2) Insert the new element in the queue till the elements are smaller or equal to it and remove all these elements. 
3) The top of the queue will be our current maximum

*Time complexity:* **O(n)**
*Space Complexity:* **O(n)**

[Source Code](https://github.com/andreacosci/competitive-programming/blob/master/SlidingWindows.cpp)

## Next Larger Element
Solution similar to the previous one. We use a stack and we scan the array backwards doing the following steps:
1) Removing from the stack each element smaller or equal the current element of the iteration.
2) If the stack is empty the element hasn't a next larger element, so put -1. Otherwise put the stack top.
3) Push the current element to the stack so, if the stack is not empty, this element will possibly be the upper bound of the next element or will be removed if smaller.

*Time complexity:* **O(n)**
*Space Complexity:* **O(n)**

[Source Code](https://github.com/andreacosci/competitive-programming/blob/master/NextLargerElement.cpp)

## Towers
We use a greedy approach. We sort the array of bars and the we simulate the construction of the towers.

*Time complexity:* **O(n log(n))**
*Space Complexity:* **O(n)**

[Source Code](https://github.com/andreacosci/competitive-programming/blob/master/Towers.cpp)

## Finding Team Member
We use a greedy approach. We build an array of triplets with the strenght of the team, the first and the second person index. Then we sort by the highest strenght. In the end we scan the array and we take the best possible team.

*Time complexity:* **O(n log(n))**
*Space Complexity:* **O(n)**

[Source Code](https://github.com/andreacosci/competitive-programming/blob/master/TeamMembers.cpp)

## Inversion Count
We use a modified version of merge sort. Each time we pick a new element from the right array, in the merge phases, we add to the inversion counter the number of elements on the left array.

*Time complexity:* **O( n log(n) )**
*Space Complexity:* **O(n)**

[Source Code](https://github.com/andreacosci/competitive-programming/blob/master/InversionCount.cpp)

## Largest Even Number
We consider the number as an array of digits. We pick the smallest even digit (smallest odd if the number hasn't any even digits) and we sort the remaining digits using the counting sort. We build the number picking the sorted digits from the biggest to the lowest and then we put the previously picked digit.

*Time complexity:* **O(n)**
*Space Complexity:* **O(n)**

[Source Code](https://github.com/andreacosci/competitive-programming/blob/master/LargestEvenNumber.cpp)

## Firing Employees
We use a DFS + DP. We store the already calculated rank in the array and, for each element without a rank, we do a depth first search to compute the rank. We do this search foreach element but only once because we store previously calculated results. Then we only need to check which had a prime rank.

*Time complexity:* **O(n)**
*Space Complexity:* **O(n)**

[Source Code](https://github.com/andreacosci/competitive-programming/blob/master/FiringEmpolyees.cpp)

## Check for BST
We know that in-order visit will print a sorted array if do on a BST. So we just do an in-order visit and we propagate the last number we saw, if it's bigger than his successor then we return false.

*Time complexity:* **O(n)**
*Space Complexity:* **O(n)**

[Source Code](https://github.com/andreacosci/competitive-programming/blob/master/CheckBST.hpp)

## Preorder Traversal and BST
Create a stack and set root variable to the smallest value possible. Then, for each element in the array (lets them be a[i]) do the following steps:

1) if a[i] is smaller than the root return false
2) otherwise remove each element from the stack top smaller than a[i] and make the last removed the new root.
3) push a[i] into the stack

*Time complexity:* **O(n)**
*Space Complexity:* **O(n)**

[Source Code](https://github.com/andreacosci/competitive-programming/blob/master/PreorderTraversal.cpp)

## Maximum Path Sum
We maintain two values in the recoursive call:
1) Maximum root to leaf path sum for the subtree rooted under current node.
2) The maximum path sum between leaves.

For every visited node X, we find the maximum root to leaf sum in left and right subtrees of X. We add the two values with X->data, and compare the sum with maximum path sum found so far.

*Time complexity:* **O( n )**
*Space Complexity:* **O( n )**

[Source Code](https://github.com/andreacosci/competitive-programming/blob/master/MaximumPathSum.hpp)

## Ilya & Queries
We compute a prefix sum to answer all queries. Lets consider the i-th iteration of the prefix sum.
The current value of the prefix sum is the previous computed value (e.g. prefix[i - 1]) plus 1 if i and i-1 character are equals, 0 otherwise.

*Time complexity:* **O( n )**
*Space Complexity:* **O( n )**
[Source Code](https://github.com/andreacosci/competitive-programming/blob/master/Ilya.cpp)

## Alice, Bob and Chocolate
We simulate Alice and Bob eating the chocolate.
We use 4 variables:
a) an i index to indicate the bar consider by Alice in a certain iteration set to the first position in the array.
b) a leftSum variable to indicate the amount of chocolate eaten by Alice in a certain iteration set to the first value in the array.
We use simmetric variable for Bob: j and rightSum set to the last position in the array and the last value in the array.

Then while i <= j we do the following steps:
1) if leftSum is smaller of equals to rightSum, we add the chocolate i to the leftSum and increase i.
2) otherwise we add the chocolate j to the rightSum and decrease j.

*Time complexity:* **O(n)**
*Space Complexity:* **O(n)**

[Source Code](https://github.com/andreacosci/competitive-programming/blob/master/AliceBobChocolate.cpp)

## Number Of Ways
Solution Adapted From:
https://github.com/rossanoventurini/CompetitiveProgramming/blob/master/Solutions.md#NumberWays

Let S be the sum of the array's elements. If the sum module 3 isn't 0 then there's no solution. Otherwise, we compute the array C which stores in position i the number of suffixes of a[i .. n] that sums to S/3. In the end we compute the sum of the prefixes of a and, every time a prefix i sums to S/3, we add c[i+2] to the result.

*Time complexity:* **O(n)**
*Space Complexity:* **O(n)**

[Source Code](https://github.com/andreacosci/competitive-programming/blob/master/NumberOfWays.cpp)

## Little Girl & Maximum Sum
We use a support array Q set all to zeros. Foreach query <l, r> we do: Q[l] += 1, Q[r] -= 1.
Then we do the Q array prefix sum.
We sort both the input array and the Q array. Then the sum will be, for each element, Q[i] times A[i].

*Time complexity:* **O( n log(n) + q log(q) )**
*Space Complexity:* **O( n + q )**

[Source Code](https://github.com/andreacosci/competitive-programming/blob/master/LittleGirl.cpp)

## Megacity
We create an array of pairs: <d, p> where d is the eulerian distance and p is the number of habitants. We sort by shorter distance and highest amount of habitants. We prefixsum the habitants and then we binary search for the amount of habitants needed.

*Time complexity:* **O(n log n)**
*Space Complexity:* **O(n)**

[Source Code](https://github.com/andreacosci/competitive-programming/blob/master/Megacity.cpp)

## Find Pair
We sort the array first. In a problem with no repetition the answer would be <a[k/n], a[k % n]> but this is not the case.
We need to weight the elements by their number of occurences. The first element can be found easly by a[k/n]. The second we have to count the occurencies of the first element let it be R, the position where we found his first occurency let it be L. So the second number will be 
(k - L*n)/R.

*Time complexity:* **O(n log(n))**
*Space Complexity:* **O(n)**

[Source Code](https://github.com/andreacosci/competitive-programming/blob/master/FindPair.cpp)

## Two Heaps

*Time complexity:* **O( :) )**
*Space Complexity:* **O( :) )**

[Source Code](https://www.google.it)

## Update the Array
We simply use a BIT tree to update/query the prefix sum in log(n) time.

*Time complexity:* **O( (u+q)log(n))**
*Space Complexity:* **O( n )**

[Source Code](https://github.com/andreacosci/competitive-programming/blob/master/UpdateArrayBIT.cpp)

## Nested Segments
We remap the segments using their position in the sorted array. Then we sort by higher left / higher right first. Then we build a BIT tree and, forech segment <L, R>, we calc the sum [L, R], and then we increse the R position by one. 

*Time complexity:* **O(n log(n))**
*Space Complexity:* **O(n)**

[Source Code](https://github.com/andreacosci/competitive-programming/blob/master/NestedSegments.cpp)

## Pashmak and Parmida's problem
Description

*Time complexity:* **O( :) )**
*Space Complexity:* **O( :) )**

[Source Code](https://www.google.it)

## Nested Segments 2.0
The same algorithm with the segment tree instead.

*Time complexity:* **O( n log(n) )**
*Space Complexity:* **O( n) **

[Source Code](https://github.com/andreacosci/competitive-programming/blob/master/NestedSegmentsST.cpp)

## Circular RMQ
Description

*Time complexity:* **O( :) )**
*Space Complexity:* **O( :) )**

[Source Code](https://www.google.it)

## Powerful Array
Description

*Time complexity:* **O( :) )**
*Space Complexity:* **O( :) )**

[Source Code](https://www.google.it)

## LCS
Description

*Time complexity:* **O( :) )**
*Space Complexity:* **O( :) )**

[Source Code](https://www.google.it)

## 0-1 Knapsack
Description

*Time complexity:* **O( :) )**
*Space Complexity:* **O( :) )**

[Source Code](https://www.google.it)

## Subset Sum
Description

*Time complexity:* **O( :) )**
*Space Complexity:* **O( :) )**

[Source Code](https://www.google.it)

## Minimum Number of Jumps
Description

*Time complexity:* **O( :) )**
*Space Complexity:* **O( :) )**

[Source Code](https://www.google.it)

## Edit Distance
Description

*Time complexity:* **O( :) )**
*Space Complexity:* **O( :) )**

[Source Code](https://www.google.it)

## LIS
Description

*Time complexity:* **O( :) )**
*Space Complexity:* **O( :) )**

[Source Code](https://www.google.it)

## LBS
Description

*Time complexity:* **O( :) )**
*Space Complexity:* **O( :) )**

[Source Code](https://www.google.it)

## Vertex Cover
Description

*Time complexity:* **O( :) )**
*Space Complexity:* **O( :) )**

[Source Code](https://www.google.it)

## LPS
Description

*Time complexity:* **O( :) )**
*Space Complexity:* **O( :) )**

[Source Code](https://www.google.it)

## N Meetings in one room
Description

*Time complexity:* **O( :) )**
*Space Complexity:* **O( :) )**

[Source Code](https://www.google.it)

## Magic Numbers
Description

*Time complexity:* **O( :) )**
*Space Complexity:* **O( :) )**

[Source Code](https://www.google.it)

## Wilbur & Array
Description

*Time complexity:* **O( :) )**
*Space Complexity:* **O( :) )**

[Source Code](https://www.google.it)

## Alternative Thinking
A very simple mathematical solution is to count the number of consecutive equal and not equal digits and store them into variables. Lets call those variable eq and dif. The answer will be dif + 1 + min(eq, 2).
Here a possible explanation: https://codeforces.com/blog/entry/21885.

*Time complexity:* **O(n)**
*Space Complexity:* **O(n)**

[Source Code](https://github.com/andreacosci/competitive-programming/blob/master/AlternativeThinking.cpp)

## LMS
Description

*Time complexity:* **O( :) )**
*Space Complexity:* **O( :) )**

[Source Code](https://www.google.it)

## WoodCutters
Description

*Time complexity:* **O( :) )**
*Space Complexity:* **O( :) )**

[Source Code](https://www.google.it)

## Queue
Description

*Time complexity:* **O( :) )**
*Space Complexity:* **O( :) )**

[Source Code](https://www.google.it)

## X Total Shapes
Description

*Time complexity:* **O( :) )**
*Space Complexity:* **O( :) )**

[Source Code](https://www.google.it)

## Is Bipartite
Description

*Time complexity:* **O( :) )**
*Space Complexity:* **O( :) )**

[Source Code](https://www.google.it)

## Fox And Names
Description

*Time complexity:* **O( :) )**
*Space Complexity:* **O( :) )**

[Source Code](https://www.google.it)

## Learning Languages
Description

*Time complexity:* **O( :) )**
*Space Complexity:* **O( :) )**

[Source Code](https://www.google.it)

## Checkposts
Description

*Time complexity:* **O( :) )**
*Space Complexity:* **O( :) )**

[Source Code](https://www.google.it)

## MST
For this problem we used a well known algorithm: Kruskal Algorith.

A description of the algorithm here:
https://en.wikipedia.org/wiki/Kruskal%27s_algorithm

*Time complexity:* **O( E log(V) )**
*Space Complexity:* **O( E + V )**

[Source Code](https://github.com/andreacosci/competitive-programming/blob/master/MST.cpp)
