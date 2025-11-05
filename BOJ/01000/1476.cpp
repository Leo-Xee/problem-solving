/**
 * 문제: 날짜 계산
 *
 * 시간 복잡도: O(1)
 *
 * 문제 요약
 * 지구 E(1-15), 태양 S(1-28), 달 M(1-19)
 * 1년 = 1 1 1
 *
 * 문제 풀이
 * 1. 반복문을 수행한다.
 * 1-1. 지구, 태양, 달의 연도가 입력과 동일하면 우리의 연도를 출력하고 반복문을 탈출한다.
 * 1-2. 우리의 연도가 지구, 태양, 달의 연도 범위를 넘으면 1로 리셋, 넘지 않으면 +1 증가시킨다.
 * 1-3. 우리의 연도를 증가시킨다.
 */

#include <bits/stdc++.h>
using namespace std;

int e, s, m;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> e >> s >> m;

  int ee = 1, ss = 1, mm = 1;
  int year = 1;

  while (true) {
    if (e == ee && s == ss && m == mm) {
      cout << year << "\n";
      break;
    }

    if (ee == 15)
      ee = 1;
    else
      ee++;
    if (ss == 28)
      ss = 1;
    else
      ss++;
    if (mm == 19)
      mm = 1;
    else
      mm++;

    year++;
  }

  return 0;
}