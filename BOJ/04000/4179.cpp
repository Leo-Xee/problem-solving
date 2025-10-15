/**
 * 문제: 불!
 *
 * 시간 복잡도: O(R * C)
 *
 * 문제 풀이
 * 1. 입력을 받는다.
 * 1-1. 지훈이와 불의 좌표를 큐에 추가하고 방문처리한다.
 * 2. 불의 좌표들에서 BFS를 수행한다. (불은 2개 이상일 수 있음!)
 * 3. 지훈이의 좌표에서 BFS를 수행한다.
 * 3-1. 다음 좌표의 최단거리값이 불의 값보다 크거나 같으면 탈출할 수 없으니 skip한다.
 * 3-2. 다음 좌표가 미로를 벗어난 경우에 현재 좌표의 최단거리값을 저장하고 반복문을 탈출한다.
 * 4. 탈출 여부에 따라 출력한다.
 */

#include <bits/stdc++.h>
using namespace std;

const int mx = 1004;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int r, c, y, x, ret;
int a[mx][mx], vis_start[mx][mx], vis_fire[mx][mx];
queue<pair<int, int>> q_start, q_fire;
bool possible = false;
string s;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> r >> c;

  for (int i = 0; i < r; i++) {
    cin >> s;
    for (int j = 0; j < c; j++) {
      if (s[j] == '.') a[i][j] = 1;
      if (s[j] == 'J') {
        a[i][j] = 1;
        vis_start[i][j] = 1;
        q_start.push({i, j});
      }
      if (s[j] == 'F') {
        a[i][j] = 1;
        vis_fire[i][j] = 1;
        q_fire.push({i, j});
      }
    }
  }

  while (q_fire.size()) {
    tie(y, x) = q_fire.front();
    q_fire.pop();

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
      if (vis_fire[ny][nx] || !a[ny][nx]) continue;

      vis_fire[ny][nx] = vis_fire[y][x] + 1;
      q_fire.push({ny, nx});
    }
  }

  while (q_start.size() && !possible) {
    tie(y, x) = q_start.front();
    q_start.pop();

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      // 다음 좌표에서 미로를 벗어날 경우에 탈출할 것이므로 현재 좌표의 최단거리를 저장하고 반복문 탈출
      if (ny < 0 || ny >= r || nx < 0 || nx >= c) {
        possible = true;
        ret = vis_start[y][x];
        break;
      }
      if (vis_start[ny][nx] || !a[ny][nx]) continue;
      // 다음 좌표의 최단거리 값이 불보다 클 경우에 탈출이 불가하기 때문에 skip
      if (vis_fire[ny][nx] && vis_start[y][x] + 1 >= vis_fire[ny][nx]) continue;

      vis_start[ny][nx] = vis_start[y][x] + 1;
      q_start.push({ny, nx});
    }
  }

  if (possible) {
    cout << ret << '\n';
  } else {
    cout << "IMPOSSIBLE" << '\n';
  }

  return 0;
}