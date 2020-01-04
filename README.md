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
Description

*Time complexity:* **O( :) )**
*Space Complexity:* **O( :) )**

[Source Code](https://www.google.it)

## Little Girl & Maximum Sum
Description

*Time complexity:* **O( :) )**
*Space Complexity:* **O( :) )**

[Source Code](https://www.google.it)

## Megacity
Description

*Time complexity:* **O( :) )**
*Space Complexity:* **O( :) )**

[Source Code](https://www.google.it)

## Find Pair
Description

*Time complexity:* **O( :) )**
*Space Complexity:* **O( :) )**

[Source Code](https://www.google.it)

## Two Heaps
Description

*Time complexity:* **O( :) )**
*Space Complexity:* **O( :) )**

[Source Code](https://www.google.it)

## Update the Array
Description

*Time complexity:* **O( :) )**
*Space Complexity:* **O( :) )**

[Source Code](https://www.google.it)

## Nested Segments
Description

*Time complexity:* **O( :) )**
*Space Complexity:* **O( :) )**

[Source Code](https://www.google.it)

## Pashmak and Parmida's problem
Description

*Time complexity:* **O( :) )**
*Space Complexity:* **O( :) )**

[Source Code](https://www.google.it)

## Nested Segments 2.0
Description

*Time complexity:* **O( :) )**
*Space Complexity:* **O( :) )**

[Source Code](https://www.google.it)

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
Description

*Time complexity:* **O( :) )**
*Space Complexity:* **O( :) )**

[Source Code](https://www.google.it)

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
Description

*Time complexity:* **O( :) )**
*Space Complexity:* **O( :) )**

[Source Code](https://www.google.it)
