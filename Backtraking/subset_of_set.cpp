#include <iostream>
using namespace std;

class Subset {
  bool flag = 0;

public:
  void PrintSubset(int set[], vector<int> &subset, int n, int sum, int index) {
    if (sum == 0) {
      flag = 1;
      cout << "[ ";
      for (int i = 0; i < subset.size(); i++) {
        cout << subset[i] << " ";
      }
      cout << "]";
      return;
    }

    if (index == n) {
      return;
    }
    // case when it will not consider the element
    PrintSubset(set, subset, n, sum, index + 1);

    // case when to consider
    if (set[index] <= sum) {
      subset.push_back(set[index]);
      PrintSubset(set, subset, n, sum - set[index], index + 1);
      subset.pop_back();
    }
  }
};
int main() {
  Subset s;
  int set[] = {1, 2, 1};
  int n = 3;
  int sum = 3;
  vector<int> subset;

  s.PrintSubset(set, subset, n, sum, 0);
}
