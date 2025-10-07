/**
 * 문제: 영화감독 숌
 *
 * 시간 복잡도: O(N * logN)
 *
 * 문제 풀이
 * 1. 1부터 값을 계속 증가시킨다.
 * 2. 증가된 값에 "666"이 존재하면 cnt를 1만큼 증가시킨다.
 * 3. 입력값과 cnt가 동일하면 반복문을 탈출한다.
 * 4. 증가된 값을 출력한다.
 */

#include <bits/stdc++.h>
using namespace std;

int n, cnt, ret;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;

  while (true) {
    ret++;
    if (to_string(ret).find("666") != string::npos) cnt++;
    if (cnt == n) break;
  }

  cout << ret << "\n";

  return 0;
}
