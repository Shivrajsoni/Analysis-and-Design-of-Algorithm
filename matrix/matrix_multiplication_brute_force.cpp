// Matrix multiplication with Complexity O(n^3)
#include <iostream>
using namespace std;
int main() {
  int m, n, o, p;
  cout << "Enter dimensions of matrix 1 and 2: ";
  cin >> m >> n >> o >> p;
  if (n != o) {
    cout << "Incompatible" << endl;
    return -1;
  }
  int a[m][n];
  int b[n][p];
  cout << "Enter elements of matrix 1: ";
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  cout << "Enter elements of matrix 2: ";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < p; j++) {
      cin >> b[i][j];
    }
  }

  int c[m][p];
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < p; j++) {
      c[i][j] = 0;
    }
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < p; j++) {
      for (int k = 0; k < n; k++) {
        c[i][j] = a[i][k] * b[k][j] + c[i][j];
      }
    }
  }

  cout << "Resultant matrix: " << endl;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < p; j++) {
      cout << c[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}
