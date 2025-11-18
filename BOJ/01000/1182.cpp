/**
 * 문제: 부분수열의 합
 *
 * 시간 복잡도: O(2^N)
 *
 * 문제 요약
 * N개의 정수의 수열의 부분 수열의 합이 S인 경우의 수 구하기
 *
 * 문제 풀이
 * 1. 수열의 각 원소를 선택하거나 선택하지 않는 경우로 나눠 깊이가 N인 트리를 구성한다.
 * 2. 깊이가 N인 경우 선택한 부분 수열의 합과 S가 동일한지 확인해 경우의 수를 1 증가한다.
 * 3. S가 0인 경우에는 공집합인 경우가 포함되므로 경우의 수를 1 감소하고 출력한다.
 */

#include <bits/stdc++.h>
using namespace std;

int n, s, cnt;
int arr[21];

void go(int cur, int sum) {
  if (cur == n) {
    if (sum == s) cnt++;
    return;
  }

  go(cur + 1, sum);
  go(cur + 1, sum + arr[cur]);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> s;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  go(0, 0);

  if (s == 0) cnt--;
  cout << cnt << "\n";

  return 0;
}
