// recursive way of solving the code
//
void fibonacci_recursive(int *n) {
  if (n == 0 | n == 1)
    return 1;
  return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

void fibonacci_using_dp(int *n) {
  int fib[0] = 1;
  int fib[1] = 1;

  for (int i = 2; i < n; i++) {
    fib[i] = fib[i - 1] + fib[n - 2];
  }
}
