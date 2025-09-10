/**
 * 문제: 불
 *
 * 시간 복잡도: O(T * W * H)
 *
 * 문제 풀이
 * 1. 테스트 케이스별로 순회한다.
 *   1. 이동하는 주체가 불과 상근이로 2개이므로 각 주체가 BFS를 수행하기 위한 큐를 정의하고 방문 배열을 초기화한다.
 *   2. 입력을 받는다.
 *     1. 벽(#)이면 0, 아니라면 1로 받는다.
 *     2. 벽과 상근이의 위치 좌표를 각각의 큐(q_fire, s_fire)에 추가하고 방문 처리한다.
 *   3. 불에 대한 BFS를 수행한다.
 *   4. 상근이에 대한 BFS를 아래 조건을 만족하도록 수행한다.
 *     1. 탈출에 성공할 때까지만 진행해야한다. (success 플래그가 true일 때까지)
 *     2. 지도를 벗어나는 순간의 현재 좌표에 해당하는 최단거리 값을 결과 배열(ret)에 추가하고 탐색을 종료한다.
 *     3. 다음 좌표에 불이 존재하고 해당 좌표에서 상근이의 최단거리 값보다 불의 최단 거리값이 큰 경우가 아니라면 skip 처리한다.
 * 2. ret을 순회하면서 출력한다.
 */

#include <bits/stdc++.h>
using namespace std;

const int mx = 1004;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int t, w, h, y, x;
int a[mx][mx], vis_fire[mx][mx], vis_start[mx][mx];
char temp;
vector<string> ret;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> t;

  while (t--) {
    fill(&vis_fire[0][0], &vis_fire[0][0] + mx * mx, 0);
    fill(&vis_start[0][0], &vis_start[0][0] + mx * mx, 0);

    queue<pair<int, int>> q_fire, q_start;
    bool success = false;

    cin >> w >> h;

    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        cin >> temp;

        if (temp == '#') {
          a[i][j] = 0;
        } else {
          a[i][j] = 1;
          if (temp == '@') {
            q_start.push({i, j});
            vis_start[i][j] = 1;
          }
          if (temp == '*') {
            q_fire.push({i, j});
            vis_fire[i][j] = 1;
          }
        }
      }
    }

    while (q_fire.size()) {
      tie(y, x) = q_fire.front();
      q_fire.pop();
      for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
        if (a[ny][nx] == 0) continue;
        if (vis_fire[ny][nx]) continue;
        vis_fire[ny][nx] = vis_fire[y][x] + 1;
        q_fire.push({ny, nx});
      }
    }

    while (q_start.size() && !success) {
      tie(y, x) = q_start.front();
      q_start.pop();
      for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= h || nx < 0 || nx >= w) {
          ret.push_back(to_string(vis_start[y][x]));
          success = true;
          break;
        }
        if (a[ny][nx] == 0) continue;
        if (vis_start[ny][nx]) continue;
        // 불이 존재하고 불의 최단거리 값이 상근이의 최단거리 값보다 적거나 같은 경우에는 지나갈 수 없으므로 skip 처리해야한다.
        if (vis_fire[ny][nx] && vis_fire[ny][nx] <= vis_start[y][x] + 1) continue;
        vis_start[ny][nx] = vis_start[y][x] + 1;
        q_start.push({ny, nx});
      }
    }
    if (!success) ret.push_back("IMPOSSIBLE");
  }

  for (auto it : ret) cout << it << "\n";

  return 0;
}