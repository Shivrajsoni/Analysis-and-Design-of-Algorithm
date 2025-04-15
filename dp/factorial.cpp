#include <iostream>
#include <vector>

using namespace std;

int MOD = 1e9 + 7;
int MAX_N = 1e5 + 1;

vector<long long> factorial(MAX_N);

void precomputeFactorials() {
  factorial[0] = 1;
  for (int i = 1; i < MAX_N; i++) {
    factorial[i] = (factorial[i - 1] * i) % MOD;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  precomputeFactorials();

  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    cout << factorial[N] << "\n";
  }

  return 0;
}
