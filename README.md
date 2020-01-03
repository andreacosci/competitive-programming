# competitive-programming
Competitive Programming and Contests Homeworks collection

## Leaders in the array
The algorithm will scan the array backwards. Every time it meets an item bigger than the last leader, will save him and update the last leader. To achieve constant memory, the algorithm will store each leader in the last free previous visited position. In fact at the k-th iteration we can have found at most (k - 1) leaders.

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
Description

*Time complexity:* **O( :) )**
*Space Complexity:* **O( :) )**

[Source Code](https://www.google.it)

## Inversion Count
Description

*Time complexity:* **O( :) )**
*Space Complexity:* **O( :) )**

[Source Code](https://www.google.it)

## Largest Even Number
Description

*Time complexity:* **O( :) )**
*Space Complexity:* **O( :) )**

[Source Code](https://www.google.it)

## Firing Employees
Description

*Time complexity:* **O( :) )**
*Space Complexity:* **O( :) )**

[Source Code](https://www.google.it)

## Check for BST
Description

*Time complexity:* **O( :) )**
*Space Complexity:* **O( :) )**

[Source Code](https://www.google.it)

## Preorder Traversal and BST
Description

*Time complexity:* **O( :) )**
*Space Complexity:* **O( :) )**

[Source Code](https://www.google.it)

## Maximum Path Sum
Description

*Time complexity:* **O( :) )**
*Space Complexity:* **O( :) )**

[Source Code](https://www.google.it)

## Ilya & Queries
Description

*Time complexity:* **O( :) )**
*Space Complexity:* **O( :) )**

## Alice, Bob and Chocolate
Description

*Time complexity:* **O( :) )**
*Space Complexity:* **O( :) )**

[Source Code](https://www.google.it)

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
