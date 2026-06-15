#include <iostream>
#include <vector>

using namespace std;
int fib(int n);
int fib_memo(int n);

vector <int> memo;

int main() {
  int n = 1000;
  memo.resize(n + 1, -1);
  cout << "El valor de n es: " << fib_memo(n) << endl;
  return 0;
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