/**
 * 문제: N과 M (2)
 *
 * 시간 복잡도: O(NCM)
 *
 * 문제 풀이
 * 1. m = 0인 케이스부터 재귀 호출을 수행한다.
 * 2. 수열이 오름차순이어야하므로 선택할 숫자가 이전에 선택된 숫자보다 큰 경우에만 다음 재귀 호출을 진행하도록 한다.
 * 3. m개의 숫자를 모두 선택한 경우에 선택된 숫자 배열(a)의 요소를 모두 출력한다.
 *
 */

#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[10];

void go(int k) {
  if (k == m) {
    for (int i = 0; i < m; i++) {
      cout << a[i] << " ";
    }
    cout << "\n";
    return;
  }

  int start = 1;
  if (k != 0) start = a[k - 1] + 1;

  for (int i = start; i <= n; i++) {
    a[k] = i;
    go(k + 1);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;

  go(0);

  return 0;
}