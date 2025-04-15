#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// naive approach
// assume str a is bigger than str b
void using_recursive(str &a, str &b, int i, int j) {
  if (i < 0)
    return 0;
  if (j < 0)
    return 1;

  if (a[i] == b[j]) {
    return (using_recursive(a, b, i - 1, j - 1) +
            using_recursive(a, b, i - 1, j));
  }
  return using_recursive(a, b, i - 1, j);
}
int main() {
  string s1 = "afkfadaf";
  string s2 = "afk";
  int i = s1.size() - 1;
  int j = s2.size() - 1;

  using_recursive(s1, s2, i, j);
}
