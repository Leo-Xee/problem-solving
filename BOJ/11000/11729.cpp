/**
 * 문제: 하노이 탑 이동 순서
 *
 * 시간 복잡도: O(2^n + 1)
 *
 * 문제 풀이
 * - 절차 지향이 아닌 수학적 귀납법으로 사고하기!!
 * - 수학적 귀납 과정
 *   - n-1개의 원판을 기둥 2로 이동시킨다.
 *   - n번 원판을 기둥 3으로 이동시킨다.
 *   - n-1개의 원판을 3으로 이동시킨다.
 * - 결론: n-1개의 원판을 이동시킬 수 있으면 원판이 n개일 때에도 이동시킬 수 있다.
 *
 */

#include <bits/stdc++.h>
using namespace std;

int n;

void func(int a, int b, int n) {  // 원판 n개를 기둥 a에서 기둥 b로 옮기는 방법을 출력하는 함수
  if (n == 1) {
    cout << a << " " << b << "\n";
    return;
  }
  func(a, 6 - a - b, n - 1);      // n-1개의 원판을 기둥 a -> 기둥 6-a-b로 이동
  cout << a << " " << b << "\n";  // n번 원판을 기둥 a -> 기둥 b로 이동
  func(6 - a - b, b, n - 1);      // n-1개의 원판을 기둥 6-a-b에서 기둥 b로 이동
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  cout << (1 << n) - 1 << "\n";  // 비트 시프트 연산으로 2^k 계산
  func(1, 3, n);

  return 0;
}