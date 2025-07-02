/**
 * 문제: 피보나치 수 5
 *
 * 시간 복잡도: O(2^N)
 * 공간 복잡도: O(N)
 *
 */
#include <bits/stdc++.h>
using namespace std;

int n;

int fibo(int num) {
  if (num == 0) return 0;
  if (num == 1) return 1;
  return fibo(num - 2) + fibo(num - 1);
}

int main() {
  cin >> n;
  cout << fibo(n) << '\n';
  return 0;
}