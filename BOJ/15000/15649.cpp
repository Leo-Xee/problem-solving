/**
 * 문제: N과 M (1)
 *
 * 시간 복잡도: O(N!)
 *
 * 문제 풀이
 * 1. 선택된 숫자들을 담을 배열(a)과 숫자의 선택 여부를 체크할 배열(is_used)를 정의한다.
 * 2. m = 0인 케이스부터 재귀 호출을 수행한다.
 * 3. 1부터 n까지 순회하고 이미 선택된 숫자가 있다면 다시 선택하지 않도록 방지한다.
 * 4 .선택된 숫자를 a에 담고 is_used에 선택 여부 갱신한다.
 * 5. 숫자 선택이 완료되었다면 원상 복구한다.
 * 6. m개의 숫자를 모두 선택한 경우에 a의 요소들을 출력한다.
 */

#include <bits/stdc++.h>
using namespace std;

int n, m, a[10], is_used[10];

void go(int k) {
  if (k == m) {
    for (int i = 0; i < m; i++) {
      cout << a[i] << " ";
    }
    cout << "\n";
    return;
  }

  for (int i = 1; i <= n; i++) {
    if (!is_used[i]) {
      a[k] = i;
      is_used[i] = 1;
      go(k + 1);
      is_used[i] = 0;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;

  go(0);

  return 0;
}