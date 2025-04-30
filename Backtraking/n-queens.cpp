#include <iostream>
using namespace std;

class Nqueens {
  // Naive approach
  // Main function to find all distinct
public:
  bool isSafe(vector<int> &board, int currRow, int currCol) {

    // Check all previously placed queens
    for (int i = 0; i < board.size(); ++i) {
      int placedRow = board[i];

      // Columns are 1-based
      int placedCol = i + 1;

      // Check if the queen is on the same diagonal
      if (abs(placedRow - currRow) == abs(placedCol - currCol)) {
        return false; // Not safe
      }
    }

    // Safe to place the queen
    return true;
  }

  void nQueenUtilNaive(int col, int n, vector<int> &board,
                       vector<vector<int>> &res, vector<bool> &visited) {

    if (col > n) {
      res.push_back(board);
      return;
    }

    // Try placing a queen in each row
    // of the current column
    for (int row = 1; row <= n; ++row) {

      // Check if the row is already used
      if (!visited[row]) {

        // Check if it's safe to place the queen
        if (isSafe(board, row, col)) {

          // Mark the row as used
          visited[row] = true;

          // Place the queen
          board.push_back(row);

          // Recur to place the next queen
          nQueenUtilNaive(col + 1, n, board, res, visited);

          // Backtrack: remove the queen
          board.pop_back();

          // Unmark row
          visited[row] = false;
        }
      }
    }
  }

  vector<vector<int>> nQueenNaiveApproach(int n) {
    vector<vector<int>> res;

    // Current board configuration
    vector<int> board;

    // Track used rows
    vector<bool> visited(n + 1, false);

    // Start solving from the first column
    nQueenUtilNaive(1, n, board, res, visited);
    return res;
  }

  void nQueenUtilBacktrackingApproach(int j, int n, vector<int> &board,
                                      vector<bool> &rows, vector<bool> &diag1,
                                      vector<bool> &diag2,
                                      vector<vector<int>> &res) {

    if (j > n) {
      // A solution is found
      res.push_back(board);
      return;
    }
    for (int i = 1; i <= n; ++i) {
      if (!rows[i] && !diag1[i + j] && !diag2[i - j + n]) {

        // Place queen
        rows[i] = diag1[i + j] = diag2[i - j + n] = true;
        board.push_back(i);

        // Recurse to the next column
        nQueenUtilBacktrackingApproach(j + 1, n, board, rows, diag1, diag2,
                                       res);

        // Remove queen (backtrack)
        board.pop_back();
        rows[i] = diag1[i + j] = diag2[i - j + n] = false;
      }
    }
  }

  // Solves the N-Queens problem and returns
  // all valid configurations.
  vector<vector<int>> nQueenBacktracking(int n) {
    vector<vector<int>> res;
    vector<int> board;

    // Rows occupied
    vector<bool> rows(n + 1, false);

    // Major diagonals (row + j) and Minor diagonals (row - col + n)
    vector<bool> diag1(2 * n + 1, false);
    vector<bool> diag2(2 * n + 1, false);

    // Start solving from the first column
    nQueenUtilBacktrackingApproach(1, n, board, rows, diag1, diag2, res);
    return res;
  }
};

int main() {
  int n = 4;
  Nqueens nQueen;

  vector<vector<int>> res = nQueen.nQueenNaiveApproach(n);

  for (int i = 0; i < res.size(); i++) {
    cout << "[";
    for (int j = 0; j < n; ++j) {
      cout << res[i][j];
      if (j != n - 1)
        cout << " ";
    }
    cout << "]\n";
  }
  return 0;
}
