
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

void generateSquare(int n) {
  vector<vector<int>> magicSquare(n, vector<int>(n, 0));

  int i = n / 2;
  int j = n - 1;

  for (int num = 1; num <= n * n;) {
    if (i == -1 && j == n) {
      j = n - 2;
      i = 0;
    } else {
      if (j == n)
        j = 0;
      if (i < 0)
        i = n - 1;
    }
    if (magicSquare[i][j]) {
      j -= 2;
      i++;
      continue;
    } else
      magicSquare[i][j] = num++;
    j++;
    i--;
  }
}

int main() {
  // cout << "Enter maximum odd size to test: ";
  int maxSize = 1001;
  // cin >> maxSize;

  const long long threshold_ns = 1e9; // 1 second in nanoseconds
  cout << "size,time(ns)\n";

  for (int n = 3; n <= maxSize; n += 2) {
    long long totalTime = 0;
    int runs = 5;

    for (int k = 0; k < runs; ++k) {
      auto start = chrono::high_resolution_clock::now();
      generateSquare(n);
      auto end = chrono::high_resolution_clock::now();
      totalTime +=
          chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    }

    long long avg = totalTime / runs;
    cout << n << "," << avg << "\n";

    if (avg > threshold_ns) {
      cerr << "⚠️  Load too high at size " << n << ". Stopping further tests.\n";
      break;
    }
  }

  return 0;
}
