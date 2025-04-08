## matrix multiplication
The Divide and Conquer approach for matrix multiplication is based on recursively breaking down large matrices into smaller submatrices, multiplying them, and combining the results. This method is particularly useful for large matrices because it reduces the number of computations compared to the traditional iterative method.

Used in large-scale simulations, physics, and engineering problems where high-speed matrix operations are required.

### Time Complexity:O(n^3)

## Strassen multiplication
- The Strassen method is an algorithm for matrix multiplication that reduces the number of multiplications compared to the standard method, making it faster for large matrices. Here's a simplified breakdown:
- Divide-and-Conquer: Split matrices into smaller submatrices, compute products cleverly, and combine results.
- Reduces Multiplications: Uses 7 multiplications instead of 8 for 2x2 matrices, leading to better complexity: O(n^log2(7))==O(n^2.807 ).


### Steps for 2 * 2 matrix

A = [A11 A12]
    [A21 A22]

B = [B11 B12]
    [B21 B22]

⚔️ The Legendary 7:
	1.	P = (A11 + A22) × (B11 + B22)
Adds both diagonals and multiplies → captures main diagonal contribution.
	2.	Q = (A21 + A22) × B11
Adds lower half of A, multiplies with top-left of B → captures A’s bottom action.
	3.	R = A11 × (B12 - B22)
A top-left times B’s right-side difference.
	4.	S = A22 × (B21 - B11)
A’s bottom-right multiplies B’s left-side difference.
	5.	T = (A11 + A12) × B22
Adds top row of A, multiplies with B’s bottom-right.
	6.	U = (A21 - A11) × (B11 + B12)
Difference of A’s vertical pairs × sum of B’s horizontal top row.
	7.	V = (A12 - A22) × (B21 + B22)
A’s right-side difference × B’s lower half sum.

C11 = P + S - T + V
C12 = R + T
C21 = Q + S
C22 = P + R - Q + U

### Fewer Multiplications: 7 recursive calls instead of 8.

	•	Traditional: O(n³)
	•	Strassen: O(n^2.81)
