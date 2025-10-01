/**
 * 문제: 기상 캐스터
 *
 * 시간 복잡도: O(H * W)
 *
 * 문제 풀이
 * 1. 구름이 있는 영역은 0, 없는 영역은 -1로 초기화한다.
 * 2. 각 행을 왼쪽부터 순회하면서 가장 가까운 구름의 위치를 추적한다.
 * 3. 구름이 없는 영역에서 가장 가까운 구름까지의 거리를 계산한다. (구름이 없으면 -1로 유지)
 */

#include <bits/stdc++.h>
using namespace std;

int h, w, a[104][104];
string s;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> h >> w;

  for (int i = 0; i < h; i++) {
    cin >> s;
    for (int j = 0; j < w; j++) {
      if (s[j] == '.') a[i][j] = -1;  // 해당 구역에 구름이 없으면 -1로 초기화
      if (s[j] == 'c') a[i][j] = 0;   // 해당 구역에 구름이 있으면 0으로 초기화
    }
  }

  for (int i = 0; i < h; i++) {
    int idx = -1;  // 가장 가까운 구름의 인덱스

    for (int j = 0; j < w; j++) {
      if (a[i][j] == 0) {
        idx = j;                         // 가장 가까운 구름 인덱스 갱신
      } else if (idx != -1) {            // 구름이 존재하는 경우에만 실행
        if (a[i][j] == -1) a[i][j] = 0;  // 구름이 없는 영역을 0으로 초기화해 계산 준비
        a[i][j] = j - idx;  // 현재 인덱스와 가장 가까운 구름 인덱스 차이를 결과 배열에 반영
      }
    }
  }

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cout << a[i][j] << " ";
    }
    cout << "\n";
  }

  return 0;
}