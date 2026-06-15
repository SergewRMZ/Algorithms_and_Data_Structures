#include <iostream>
#include <vector>

using namespace std;
int fib(int n);
int fib_memo(int n);
int fibo_bottom_up(int n);

vector <int> memo;

int main() {
  int n = 1000;
  memo.resize(n + 1, -1);
  cout << "El valor de n es: " << fibo_bottom_up(n) << endl;
  return 0;
}

int fibo_bottom_up(int n) {
  vector<int> fibo(n);
  fibo[0] = 1; fibo[1] = 1;

  for (int i = 2; i <= n; i++) {
    fibo[i] = fibo[i - 1] + fibo[i - 2];
  }

  return fibo[n];
}

int fib(int n) {
  if(n <= 1) {
    return n;
  }

  return fib(n - 1) + fib(n - 2);
}

int fib_memo(int n) {
  if (n <= 1) {
    return n;
  }

  if(memo[n] != -1) {
    return memo[n];
  }

  memo[n] = fib_memo(n - 1) + fib_memo(n - 2);
  return memo[n];
}