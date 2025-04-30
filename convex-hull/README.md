The Convex Hull Algorithm is used to find the convex hull of a set of points in computational geometry. The convex hull is the smallest convex set that encloses all the points, forming a convex polygon. This algorithm is important in various applications such as image processing, route planning, and object modeling.

The convex hull of a set of points in a Euclidean space is the smallest convex polygon that encloses all of the points. In two dimensions (2D), the convex hull is a convex polygon, and in three dimensions (3D), it is a convex polyhedron.

### Convex Hull using Divide and Conquer Algorithm:
#### Pre-requisite: Tangents between two convex polygons 

#### Algorithm: Given the set of points for which we have to find the convex hull. Suppose we know the convex hull of the left half points and the right half points, then the problem now is to merge these two convex hulls and determine the convex hull for the complete set.
- This can be done by finding the upper and lower tangent to the right and left convex hulls. This is illustrated here Tangents between two convex polygons Let the left convex hull be a and the right convex hull be b.
- Then the lower and upper tangents are named as 1 and 2 respectively, as shown in the figure. Then the red outline shows the final convex hull.

- Now the problem remains, how to find the convex hull for the left and right half. Now recursion comes into the picture, we divide the set of points until the number of points in the set is very small, say 5, and we can find the convex hull for these points by the brute algorithm.
- The merging of these halves would result in the convex hull for the complete set of points. Note: We have used the brute algorithm to find the convex hull for a small number of points and it has a time complexity of O(N^3).
- But some people suggest the following, the convex hull for 3 or fewer points is the complete set of points. This is correct but the problem comes when we try to merge a left convex hull of 2 points and right convex hull of 3 points, then the program gets trapped in an infinite loop in some special cases.
- So, to get rid of this problem I directly found the convex hull for 5 or fewer points by O(N^3) algorithm, which is somewhat greater but does not affect the overall complexity of the algorithm.
