#include <bits/stdc++.h>
using namespace std;

void MaxMin(vector<int> &arr, int i, int j, int &maxVal, int &minVal) {
  if (i == j) {
    // Base case: Only one element
    maxVal = minVal = arr[i];
  } else if (i == j - 1) {
    // Base case: Two elements
    if (arr[i] < arr[j]) {
      maxVal = arr[j];
      minVal = arr[i];
    } else {
      maxVal = arr[i];
      minVal = arr[j];
    }
  } else {
    int mid = (i + j) / 2;
    int max1, min1;

    MaxMin(arr, i, mid, maxVal, minVal);
    MaxMin(arr, mid + 1, j, max1, min1);

    if (maxVal < max1)
      maxVal = max1;
    if (minVal > min1)
      minVal = min1;
  }
}

int main() {
  vector<int> arr = {3, 1, 8, 5, 2, 9, 7, 6};
  int n = arr.size();

  int maxVal, minVal;
  MaxMin(arr, 0, n - 1, maxVal, minVal);
  cout << "Maximum value: " << maxVal << endl;
  cout << "Minimum value: " << minVal << endl;
}
