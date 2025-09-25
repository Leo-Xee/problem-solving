/**
 * 문제: 보물섬
 *
 * 시간 복잡도: O(50^4)
 *
 * 문제 풀이
 * 1. 모든 육지에서 BFS를 수행하여 각 지점에서 가장 먼 육지까지의 거리를 계산한다.
 * 2. 모든 BFS 결과 중 최대값이 보물 사이의 최단 거리이므로 이를 출력한다.
 *
 */

#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int h, w, max_time;
string s;
int a[54][54], visited[54][54];

void bfs(int y, int x) {
  queue<pair<int, int>> q;
  visited[y][x] = 1;
  q.push({y, x});

  while (q.size()) {
    tie(y, x) = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
      if (!a[ny][nx] || visited[ny][nx]) continue;

      visited[ny][nx] = visited[y][x] + 1;
      q.push({ny, nx});
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> h >> w;

  for (int i = 0; i < h; i++) {
    cin >> s;
    for (int j = 0; j < w; j++) {
      if (s[j] == 'L') a[i][j] = 1;  // 육지는 1, 바다는 0
    }
  }

  // 모든 육지에서 BFS를 수행하여 최대 거리 찾기
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (a[i][j]) {                          // 육지인 경우
        memset(visited, 0, sizeof(visited));  // 방문 배열 초기화
        bfs(i, j);                            // 현재 위치에서 BFS 수행

        // 현재 BFS에서 가장 먼 거리 찾기
        for (int y = 0; y < h; y++) {
          for (int x = 0; x < w; x++) {
            if (visited[y][x] > 0) {
              max_time = max(max_time, visited[y][x] - 1);
            }
          }
        }
      }
    }
  }

  cout << max_time << "\n";

  return 0;
}