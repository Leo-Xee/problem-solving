/**
 * 문제: N-Queen
 *
 * 시간 복잡도: O(N! * N): 백트래킹 + 한번의 배치 시에 검증
 * 공간 복잡도: O(N)
 *
 * 문제 요약
 * 서로의 퀸은 같은 행과 열, 같은 대각선에서 충돌
 * 충돌하지 않고 행마다 하나의 퀸을 놓을 수 있는 경우의 수 구하기
 *
 * 문제 풀이
 * 처음 생각해보면 2차원 배열이 필요할 것 같지만 문제 상 하나의 행에 하나의 퀸만 위치할 수 있어서 1차원 배열로도 가능하다.
 * 1. 각 행마다 퀸을 하나씩 위치시킨다고 생각하고 다음의 행에서 어떤 열에 퀸을 위치 시켜야할 지 백트래킹을 수행한다.
 * 2. 현재 행의 퀸 위치와 이전 행의 퀸 위치가 다음 조건을 충돌하지 않을 경우에만 계속 진행한다.
 * 2-1. 같은 열: 현재열 == 이전 행의 열
 * 2-2. 같은 대각선: |현재 행 - 이전 행| == |현재 열 - 이전 열|
 */

#include <bits/stdc++.h>
using namespace std;

int n, ret;
int arr[15];

void go(int cur) {
  // 마지막 행에 도달하면 경우의 수 증가
  if (cur == n) {
    ret++;
    return;
  }

  for (int i = 0; i < n; i++) {
    arr[cur] = i;
    bool is_possible = true;

    for (int j = 0; j < cur; j++) {
      /**
       * arr[cur] == arr[j]: 같은 열에 위치해 있는지 판단
       * abs(arr[cur] - arr[j]) == cur - j: 대각선 상에 위치해 있는지 판단 (|x1 - x2| == |y1 - y2| 인 경우 대각선에 위치한다.)
       */
      if (arr[cur] == arr[j] || abs(arr[cur] - arr[j]) == cur - j) {
        is_possible = false;
        break;
      }
    }

    if (is_possible) go(cur + 1);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  go(0);
  cout << ret << '\n';

  return 0;
}