/**
 * 문제: 교수가 된  현우
 *
 * 시간 복잡도: O(T * logN)
 *
 * 문제 풀이
 * 0. 10억의 팩토리얼 값은 숫자 범위를 초과하므로 10을 구성하는 2와 5를 활용해야한다.
 * 1. 특정한 값을 2 or 5의 거듭제곱으로 나눈 몫이 2와 5가 포함된 개수를 나타낸다. (ex. 10 / 2 = 5, 2는 10까지의 숫자까지 5번 포함)
 * 2. 위의 성질을 활용해 2와 5가 포함된 개수를 더하고 두 개수의 최소값을 출력한다.
 */

#include <bits/stdc++.h>
using namespace std;

int t, n;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> t;

  while (t--) {
    int two = 0;
    int five = 0;
    cin >> n;

    for (int i = 2; i <= n; i *= 2) {
      two += n / i;  // 2에서 n까지 각 숫자가 2의 배수로 몇 번 포함되는지 계산
    }

    for (int i = 5; i <= n; i *= 5) {
      five += n / i;  // 5에서 n까지 각 숫자가 2의 배수로 몇 번 포함되는지 계산
    }

    cout << min(two, five) << "\n";
  }

  return 0;
}