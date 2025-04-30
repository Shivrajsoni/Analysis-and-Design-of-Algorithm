#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

// naive approach
// assume str a is bigger than str b
// void using_recursive(str &a, str &b, int i, int j) {
//   if (i < 0)
//     return 0;
//   if (j < 0)
//     return 1;

//   if (a[i] == b[j]) {
//     return (using_recursive(a, b, i - 1, j - 1) +
//             using_recursive(a, b, i - 1, j));
//   }
//   return using_recursive(a, b, i - 1, j);
// }

// dp approach

void using_memorization(str &a ,str &b , int i , int j){
  
  int LCS_table[m + 1][n + 1];
  // Building the mtrix in bottom-up way
  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
      if (i == 0 || j == 0)
        LCS_table[i][j] = 0;
      else if (S1[i - 1] == S2[j - 1])
        LCS_table[i][j] = LCS_table[i - 1][j - 1] + 1;
      else
        LCS_table[i][j] = max(LCS_table[i - 1][j], LCS_table[i][j - 1]);
    }
  }

  int index = LCS_table[m][n];
  char lcsAlgo[index + 1];
  lcsAlgo[index] = '\0';

  int i = m, j = n;
  while (i > 0 && j > 0) {
    if (S1[i - 1] == S2[j - 1]) {
      lcsAlgo[index - 1] = S1[i - 1];
      i--;
      j--;
      index--;
    }

    else if (LCS_table[i - 1][j] > LCS_table[i][j - 1])
      i--;
    else
      j--;
  }
  
  // Printing the sub sequences
  cout << "S1 : " << S1 << "\nS2 : " << S2 << "\nLCS: " << lcsAlgo << "\n";
}

int main() {
  string s1 = "afkfadaf";
  string s2 = "afk";
  int i = s1.size() - 1;
  int j = s2.size() - 1;

  using_recursive(s1, s2, i, j);
  using_memorization(s1,s2,i,j);
}
