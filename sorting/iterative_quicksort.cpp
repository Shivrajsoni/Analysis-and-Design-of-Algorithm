#include <chrono>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// Partition function (same as recursive QuickSort)
int partition(vector<int> arr, int low, int high) {
  int pivot = arr[high]; // Choose last element as pivot
  int i = low - 1;       // Index of smaller element

  for (int j = low; j < high; j++) {
    if (arr[j] < pivot) {
      i++;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i + 1], arr[high]); // Place pivot in correct position
  return i + 1;                // Return pivot index
}

// Iterative QuickSort
void iterative_quick_sort(vector<int> arr, int low, int high) {
  stack<pair<int, int>> stk;
  stk.push({low, high}); // Initialize stack with entire array

  while (!stk.empty()) {
    auto [l, h] = stk.top();
    stk.pop();

    if (l >= h)
      continue; // Base case: subarray of size 0/1

    int pivot_idx = partition(arr, l, h);

    // Push left and right subarrays to stack
    stk.push({l, pivot_idx - 1});
    stk.push({pivot_idx + 1, h});
  }
}

// Example usage
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
      iterative_quick_sort(a, 0, n - 1);
      auto end = std::chrono::high_resolution_clock::now();
      auto duration =
          std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
      res += duration.count();
    }
    cout << "," << res / 10 << "\n";
  }
}
