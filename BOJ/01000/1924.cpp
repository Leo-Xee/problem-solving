/**
 * 문제: 2007년
 *
 * 시간 복잡도: O(1)
 *
 * 문제 풀이
 * 1. 월별 일수(days)와 요일 배열(daysOfWeek) 정의합니다.
 *   1. days의 경우에는 직전 월의 일수까지만 합산하기 때문에 첫 번째 인덱스에 0 추가합니다.
 * 2. 입력 월(x) 직전까지 순회합니다.
 *   2. 월별 일수를 전체 일수(total)에 누적합니다.
 * 3. 누적 일수에 입력 일(y)을 합산합니다.
 * 4. 누적 일수에 7로 모듈러 연산한 값에 해당하는 인덱스의 요일 배열 요소를 출력합니다.
 */

#include <bits/stdc++.h>
using namespace std;

int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string daysOfWeek[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

int x, y, total;

int main() {
  cin >> x >> y;
  for (int i = 0; i < x; i++) total += days[i];
  total += y;
  cout << daysOfWeek[total % 7];

  return 0;
}