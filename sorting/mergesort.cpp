#include <chrono>
#include <ctime>
#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int l, int m, int r) {
  int n1 = m - l + 1;
  int n2 = r - m;

  vector<int> L(n1), R(n2);
  for (int i = 0; i < n1; ++i)
    L[i] = arr[l + i];
  for (int j = 0; j < n2; ++j)
    R[j] = arr[m + 1 + j];

  int i = 0, j = 0, k = l;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k++] = L[i++];
    } else {
      arr[k++] = R[j++];
    }
  }

  while (i < n1)
    arr[k++] = L[i++];
  while (j < n2)
    arr[k++] = R[j++];
}

void mergeSort(vector<int> &arr, int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
  }
}

int main() {
  srand(time(NULL));
  cout << "size,time\n";

  for (int n = 1000; n <= 10000; n += 1000) {
    cout << n;
    long long totalTime = 0;

    for (int t = 0; t < 10; ++t) {
      vector<int> arr(n);
      for (int i = 0; i < n; ++i)
        arr[i] = rand();

      auto start = chrono::high_resolution_clock::now();
      mergeSort(arr, 0, n - 1);
      auto end = chrono::high_resolution_clock::now();

      auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
      totalTime += duration.count();
    }

    cout << "," << totalTime / 10 << "\n";
  }

  return 0;
}
