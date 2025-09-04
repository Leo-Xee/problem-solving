/**
 * 문제: 치즈
 *
 * 시간 복잡도: O(NM)
 *
 * 문제 풀이
 * 1. 주어진 판에 치즈가 모두 사라질 때까지 반복한다. (최대 N*M번)
 *   1. 방문 배열(visited)과 치즈의 가장자리 좌표를 담을 벡터(v)를 먼저 초기화한다.
 *   2. 판의 가장자리에는 치즈가 없으므로 (0, 0)에서 시작해서 BFS를 수행한다.
 *     1. 치즈가 있는 경우 v에 해당 좌표를 추가한다.
 *   3. 한 시간 뒤 녹을 치즈의 개수(cnt2)를 갱신한다.
 *   4. v를 순회하면서 해당 좌표의 치즈를 녹인다.
 *   5. 치즈가 모두 녹는데 걸리는 시간(cnt1)을 1만큼 증가시킨다.
 *   6. 주어진 판에 치즈의 존재 여부를 파악하기 위해 순회하고 없다면 while문을 빠져나온다.
 * 2. cnt1과 cnt2를 출력한다.
 */

#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int n, m, cnt1, cnt2;
int a[104][104], visited[104][104];
vector<pair<int, int>> v;

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

      if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
      if (visited[ny][nx]) continue;
      if (a[ny][nx] == 1) {
        v.push_back({ny, nx});
        visited[ny][nx] = 1;
        continue;
      }
      visited[ny][nx] = 1;
      q.push({ny, nx});
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }

  while (true) {
    fill(&visited[0][0], &visited[0][0] + 104 * 104, 0);
    v.clear();

    bfs(0, 0);
    cnt2 = v.size();

    for (auto it : v) {
      a[it.first][it.second] = 0;
    }

    bool hasCheesee = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (a[i][j] != 0) {
          hasCheesee = 1;
        }
      }
    }
    cnt1++;
    if (!hasCheesee) break;
  }

  cout << cnt1 << "\n";
  cout << cnt2 << "\n";

  return 0;
}