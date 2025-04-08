#include <chrono>
#include <iostream>
#include <vector>

using namespace std;

class Matrix {
public:
  void initializeMatrix(vector<vector<int>> &matrix, int size) {
    matrix.assign(size, vector<int>(size, 0));
  }

  void addMatrix(const vector<vector<int>> &a, const vector<vector<int>> &b,
                 vector<vector<int>> &result, int size) {
    for (int i = 0; i < size; ++i)
      for (int j = 0; j < size; ++j)
        result[i][j] = a[i][j] + b[i][j];
  }

  void matMul(const vector<vector<int>> &a, const vector<vector<int>> &b,
              vector<vector<int>> &c, int size) {
    if (size == 1) {
      c[0][0] = a[0][0] * b[0][0];
      return;
    }

    int newSize = size / 2;
    vector<vector<int>> A11(newSize, vector<int>(newSize)),
        A12(newSize, vector<int>(newSize)), A21(newSize, vector<int>(newSize)),
        A22(newSize, vector<int>(newSize)), B11(newSize, vector<int>(newSize)),
        B12(newSize, vector<int>(newSize)), B21(newSize, vector<int>(newSize)),
        B22(newSize, vector<int>(newSize)), C11(newSize, vector<int>(newSize)),
        C12(newSize, vector<int>(newSize)), C21(newSize, vector<int>(newSize)),
        C22(newSize, vector<int>(newSize)),
        temp1(newSize, vector<int>(newSize)),
        temp2(newSize, vector<int>(newSize));

    for (int i = 0; i < newSize; i++) {
      for (int j = 0; j < newSize; j++) {
        A11[i][j] = a[i][j];
        A12[i][j] = a[i][j + newSize];
        A21[i][j] = a[i + newSize][j];
        A22[i][j] = a[i + newSize][j + newSize];

        B11[i][j] = b[i][j];
        B12[i][j] = b[i][j + newSize];
        B21[i][j] = b[i + newSize][j];
        B22[i][j] = b[i + newSize][j + newSize];
      }
    }

    matMul(A11, B11, temp1, newSize);
    matMul(A12, B21, temp2, newSize);
    addMatrix(temp1, temp2, C11, newSize);

    matMul(A11, B12, temp1, newSize);
    matMul(A12, B22, temp2, newSize);
    addMatrix(temp1, temp2, C12, newSize);

    matMul(A21, B11, temp1, newSize);
    matMul(A22, B21, temp2, newSize);
    addMatrix(temp1, temp2, C21, newSize);

    matMul(A21, B12, temp1, newSize);
    matMul(A22, B22, temp2, newSize);
    addMatrix(temp1, temp2, C22, newSize);

    for (int i = 0; i < newSize; i++) {
      for (int j = 0; j < newSize; j++) {
        c[i][j] = C11[i][j];
        c[i][j + newSize] = C12[i][j];
        c[i + newSize][j] = C21[i][j];
        c[i + newSize][j + newSize] = C22[i][j];
      }
    }
  }
};

int main() {
  int n;
  cout << "Enter matrix size (must be power of 2): ";
  cin >> n;

  vector<vector<int>> a(n, vector<int>(n));
  vector<vector<int>> b(n, vector<int>(n));
  vector<vector<int>> c(n, vector<int>(n, 0));

  cout << "Enter elements of matrix A:\n";
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> a[i][j];

  cout << "Enter elements of matrix B:\n";
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> b[i][j];

  Matrix m;

  auto start = chrono::high_resolution_clock::now();

  m.matMul(a, b, c, n);

  auto end = chrono::high_resolution_clock::now();
  chrono::duration<double, std::micro> duration = end - start;

  cout << "Result Matrix:\n";
  for (auto &row : c) {
    for (int val : row)
      cout << val << " ";
    cout << endl;
  }

  cout << "\nTime taken for matrix multiplication: " << duration.count()
       << " microseconds" << endl;

  return 0;
}
