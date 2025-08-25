/**
 * 문제: 나이트의 이동
 *
 * 시간 복잡도: O(I^2)
 *
 * 문제 풀이
 * 1. 나이트의 이동 특성을 반영한 방향 벡터(dy, dx)를 정의한다.
 * 2. 테스트 케이스별로 순회한다.
 *   1. 맵(a)을 방문 여부도 포함하기 위해 -1로 초기화한다.
 * 3. 현재 좌표(sy, sx)에서 시작하여 BFS를 수행한다.
 *   1. 특정 좌표를 방문할 때마다 해당 좌표에 이동 횟수를 갱신한다.
 * 4. 결과 벡터(ret)에 종료 좌표(ey, ex)에 갱신된 이동 횟수를 추가한다.
 * 5. 결과 벡터를 순회하면서 요소를 출력한다.
 */

#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};

int t, s, sy, sx, ey, ex;
int a[301][301];
vector<int> ret;

void bfs(int sy, int sx) {
  queue<pair<int, int>> q;
  a[sy][sx] = 0;
  q.push({sy, sx});
  while (q.size()) {
    tie(sy, sx) = q.front();
    q.pop();
    for (int i = 0; i < 8; i++) {
      int ny = sy + dy[i];
      int nx = sx + dx[i];
      if (ny < 0 || ny >= s || nx < 0 || nx >= s) continue;
      if (a[ny][nx] >= 0) continue;
      a[ny][nx] = a[sy][sx] + 1;
      q.push({ny, nx});
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> t;
  for (int i = 0; i < t; i++) {
    fill(&a[0][0], &a[0][0] + 301 * 301, -1);

    cin >> s;
    cin >> sy >> sx;
    cin >> ey >> ex;

    bfs(sy, sx);
    ret.push_back(a[ey][ex]);
  }

  for (auto it : ret) cout << it << "\n";

  return 0;
};