### Min-Max of an array using Divide and Conquer Method:
The Min-Max problem is about finding the minimum and maximum elements in an array. Instead of using a simple linear scan (which takes O(n) time), we can use the Divide and Conquer approach to optimize it.

Used in: Game Theory: Minimax algorithm in decision-making and AI (e.g., Chess, Tic-Tac-Toe) & Computational Geometry: Finding bounding box (smallest and largest points) in a dataset.

Steps:

1.If the array has only one element, both min and max are that element.

2.If the array has two elements, compare them and assign the smaller to min and the larger to max.

3.If the array has more than two elements, divide the array into two halves.

4.Recursively find the min and max in the left half and the right half.

5.Then, compare the two minimums to get the overall min, and compare the two maximums to get the overall max.

6.Return the final min and max values after combining the results from both halves.

The iterative approach takes 2(n-1) comparisons in the worst case. The divide-and-conquer approach takes only ~3n/2 comparisons, making it more efficient.

### Binary Search in an array using Divide and Conquer


### Time Complexity:
Time Complexity
T(n) = T(n/2) + c

the solution for above reoccurrence is Theta( Logn )


