#include <iostream>
using namespace std;

void selection_sort(int arr[], int n) {

  for (int i = 0; i < n - 1; i++) {
    int min_index = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[min_index]) {
        min_index = j;
      }
    }
    // swap
    swap(arr[i], arr[min_index]);
  }
}

void print_array(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
}

int main() {
  int arr[] = {2, 8, 1, 6, 4, 5, 3};
  int n = 7;
  cout << "Original Vector ";
  print_array(arr);

  selection_sort(arr, n);
  cout << "Sorted Vector ";
  print_array(arr, n);

  return 0;
}
