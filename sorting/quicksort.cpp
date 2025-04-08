
// quick sort algorithm complexity analysis
#include <chrono>
#include <ctime>
#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &a, int l, int h) {
  int pivot = a[l];

  int i = l + 1;
  int j = h;
  while (i <= j) {
    if (a[i] < pivot && i <= h) {
      i++;
    }
    if (a[j] > pivot && j > l) {
      j--;
    } else {
      break;
    }
    swap(a[i], a[j]);
  }
  swap(a[l], a[i - 1]);

  return i - 1;
}

void quickSort(vector<int> &a, int l, int h) {
  if (l < h) {
    int p = partition(a, l, h);
    quickSort(a, l, p - 1);
    quickSort(a, p + 1, h);
  }
}

int main() {
  srand(time(NULL));
  cout << "size,time\n";
  for (int n = 1000; n <= 10000; n += 1000) {
    cout << n;
    long res = 0;
    for (int k = 0; k < 10; ++k) {
      vector<int> a(n, 0);
      for (int j = 0; j < n; j++) {
        a[j] = rand();
      }
      auto start = std::chrono::high_resolution_clock::now();
      quickSort(a, 0, n - 1);
      auto end = std::chrono::high_resolution_clock::now();
      auto duration =
          std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
      res += duration.count();
    }
    cout << "," << res / 10 << "\n";
  }
  return 0;
}
