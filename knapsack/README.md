## FRACTIONAL KNAPSACK
The basic idea of the greedy approach is to calculate the ratio profit/weight for each item and sort the item on the basis of this ratio. Then take the item with the highest ratio and add them as much as we can (can be the whole element or a fraction of it).


This will always give the maximum profit because, in each step it adds an element such that this is the maximum possible profit for that much weight.

### Follow the given steps to solve the problem using the above approach:

- Calculate the ratio (profit/weight) for each item.
- Sort all the items in decreasing order of the ratio.
- Initialize res = 0, curr_cap = given_cap.
- Do the following for every item i in the sorted order:
- If the weight of the current item is less than or equal to the remaining capacity then add the value of that item into the result
- Else add the current item as much as we can and break out of the loop.
- Return res.
