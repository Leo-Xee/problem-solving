/**
 * 문제: 적록색약
 *
 * 시간 복잡도: O(N^2)
 *
 * 문제 풀이
 * 1. 일반 케이스와 적록색약 케이스를 구분해서 BFS를 수행한다.
 *   1. 일반 케이스는 입력 받은 그리드(a)대로 진행하되 다음 좌표의 색상이 현재 좌표의 색상과 경우에 진행한다.
 *   2. 적록색약 케이스는 빨강과 초록을 구분하지 못하므로 a의 좍표값이 R이면 G로 변경한 후 동일하게 진행한다.
 * 2. 각 케이스의 구역의 수를 결과 배열(ret)에 반영한다.
 * 3. ret을 출력한다.
 */

#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int n;
char a[104][104];
int visited[104][104], ret[2];

void bfs(int y, int x) {
  queue<pair<int, int>> q;
  q.push({y, x});
  visited[y][x] = 1;

  while (q.size()) {
    tie(y, x) = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
      if (!visited[ny][nx] && a[y][x] == a[ny][nx]) {
        q.push({ny, nx});
        visited[ny][nx] = 1;
      }
    }
  }
}

int main() {
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf(" %c", &a[i][j]);
    }
  }

  for (int num = 0; num < 2; num++) {
    int cnt = 0;
    fill(&visited[0][0], &visited[0][0] + 104 * 104, 0);

    if (num == 1) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (a[i][j] == 'R') {
            a[i][j] = 'G';
          }
        }
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (!visited[i][j]) {
          bfs(i, j);
          cnt++;
        }
      }
    }

    ret[num] = cnt;
  }

  for (auto it : ret) printf("%d ", it);

  return 0;
}