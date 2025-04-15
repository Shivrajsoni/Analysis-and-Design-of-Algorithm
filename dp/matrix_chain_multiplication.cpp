
#include <climits> // For INT_MAX
#include <iostream>
#include <vector>

using namespace std;

int matrixChainMultiplication(vector<int> &arr) {
  int n = arr.size();
  vector<vector<int>> dp(n, vector<int>(n, 0));

  // dp[i][j] = minimum number of multiplications needed to compute the product
  // of matrices A[i]...A[j]
  for (int len = 2; len < n; len++) { // len is the chain length
    for (int i = 1; i < n - len + 1; i++) {
      int j = i + len - 1;
      dp[i][j] = INT_MAX;

      for (int k = i; k < j; k++) {
        int cost = arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j];
        dp[i][j] = min(dp[i][j], cost);
      }
    }
  }

  return dp[1][n - 1]; // Answer: minimum cost to multiply from matrix 1 to n-1
}

int main() {
  vector<int> arr = {40, 20, 30, 10,
                     30}; // Example: 4 matrices: 40x20, 20x30, 30x10, 10x30
  cout << "Minimum number of multiplications: "
       << matrixChainMultiplication(arr) << endl;
  return 0;
}
