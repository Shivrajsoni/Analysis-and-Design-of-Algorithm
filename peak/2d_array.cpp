#include <chrono>
#include <ctime>
#include <iostream>
using namespace std;

#define N 5

int peak(int **a, int y1, int y2, int x1, int x2, int n) {
  // if(y2>=y1 || x2>=x1){
  //   return -1;
  // }
  int m1 = (y1 + y2) / 2;
  int m2 = (x1 + x2) / 2;
  if (m2 < n - 1 && x2 > m2 + 1 && a[m1][m2] < a[m1][m2 + 1]) {
    return peak(a, y1, y2, m2 + 1, x2, n);
  } else if (m2 > 0 && x1 < m2 - 1 && a[m1][m2] < a[m1][m2 - 1]) {
    return peak(a, y1, y2, x1, m2 - 1, n);
  } else if (m1 < n - 1 && y2 > m1 + 1 && a[m1][m2] < a[m1 + 1][m2]) {
    return peak(a, m1 + 1, y2, x1, x2, n);
  } else if (m1 > 0 && y1 < m1 - 1 && a[m1][m2] < a[m1 - 1][m2]) {
    return peak(a, y1, m1 - 1, x1, x2, n);
  } else {
    return a[m1][m2];
  }
}

int main() {

  srand(time(NULL));
  cout << "size,time\n";
  for (int n = 100; n <= 1500; n += 50) {
    cout << n;
    long res = 0;
    for (int k = 0; k < 10; ++k) {
      int **a = new int *[n];
      for (int i = 0; i < n; i++) {
        a[i] = new int[n];
        for (int j = 0; j < n; ++j) {
          a[i][j] = rand();
        }
      }
      int stack = 0;
      int maxStack = 0;

      auto start = std::chrono::high_resolution_clock::now();
      peak(a, 0, n - 1, 0, n - 1, n);
      auto end = std::chrono::high_resolution_clock::now();
      auto duration =
          std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
      res += duration.count();
    }
    cout << "," << res / 10 << "\n";
  }
  return 0;
}
