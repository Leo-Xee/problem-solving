/**
 * 문제: 팩토리얼 2
 *
 * 시간 복잡도: O(N)
 * 공간 복잡도: O(N)
 *
 */

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int num;

ll fact(ll n) {
  if (n <= 1) return 1;
  return fact(n - 1) * n;
}

int main() {
  cin >> num;
  cout << fact(num) << '\n';
  return 0;
}