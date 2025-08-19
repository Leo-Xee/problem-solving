/**
 * 문제: 안전 영역
 *
 * 시간 복잡도: O(N^2)
 *
 * 문제 풀이
 * 1. 높이 정보(d)만큼 순회한다.
 *   1. 방문 배열(visited), 안전 영역 개수(cnt) 초기화한다.
 *   2. 전체 좌표 탐색을 위해 순회한다.
 *     1. 특정 좌표가 d를 초과하고 방문한 좌표가 아닌 경우에 bfs를 진행하고 cnt를 1 증가한다.
 *   3. 안전 영역의 최대 개수(ret)와 cnt 중 큰 값을 ret에 갱신한다.
 * 2. ret을 출력한다.
 */

#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int n, limit, ret = 1;
int a[104][104], visited[104][104];

void bfs(int y, int x, int d) {
  queue<pair<int, int>> q;
  visited[y][x] = 1;
  q.push({y, x});

  while (q.size()) {
    tie(y, x) = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
      if (a[ny][nx] > d && !visited[ny][nx]) {
        visited[ny][nx] = 1;
        q.push({ny, nx});
      }
    }
  }
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }

  for (int d = 0; d <= 100; d++) {
    fill(&visited[0][0], &visited[0][0] + 104 * 104, 0);
    int cnt = 0;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (a[i][j] > d && !visited[i][j]) {
          bfs(i, j, d);
          cnt++;
        }
      }
    }
    ret = max(ret, cnt);
  }

  cout << ret << "\n";

  return 0;
}
