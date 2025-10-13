/**
 * 문제: 연구소
 *
 * 시간 복잡도: O(NMC3 * (2NM))
 * - N과 M이 8이하로 제한되어 있어 가능
 *
 * 문제 풀이
 * 1. 입력과 함께 빈 칸과 바이러스의 좌표를 벡터에 추가한다.
 * 2. 벡터에서 빈 칸의 좌표에서 3개를 뽑은 경우마다 순회한다.
 *   2-1. 뽑은 좌표에 벽을 세운다.
 *   2-2. 퍼뜨린 바이러스를 표시한 방문배열을 초기화한다.
 *   2-3. 바이러스 좌표를 기준으로 BFS를 수행해 인접한 좌표가 빈공간(0)이면 바이러스(2)를 퍼뜨린다.
 *   2-4. 안전 영역(0)의 개수를 세고 최대값을 갱신한다.
 *   2-5. 뽑은 좌표에 벽을 세운 처리를 원상복구한다.
 * 3. 안전 영역의 최댓값을 출력한다.
 */

#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int n, m;
int a[10][10], vis[10][10];
vector<pair<int, int>> none_list, virus_list, wall_list;
int ret = -1;

void bfs(int y, int x) {
  queue<pair<int, int>> q;
  vis[y][x] = 1;
  q.push({y, x});

  while (q.size()) {
    tie(y, x) = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;  // 오버플로우 방지
      if (vis[ny][nx] || a[ny][nx] == 1) continue;           // 방문했거나 벽인 경우 스킵

      vis[ny][nx] = 1;
      q.push({ny, nx});
    }
  }
}

// 빈 칸에서 3개의 벽을 세우는 조합 수행
void combi(int start, int depth, vector<pair<int, int>>& wall_list) {
  if (depth == 3) {
    for (auto it : wall_list) a[it.first][it.second] = 1;  // 벽을 3개 세움
    memset(vis, 0, sizeof(vis));                          // 퍼진 바이러스를 표시한 방문 배열 초기화
    for (auto it : virus_list) bfs(it.first, it.second);  // 바이러스를 퍼뜨리고 방문배열에 표시

    int cnt = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (a[i][j] == 0 && !vis[i][j]) cnt++;  // 안전 영역을 카운트
      }
    }

    ret = max(ret, cnt);                                   // 안전 영역의 최대값을 갱신
    for (auto it : wall_list) a[it.first][it.second] = 0;  // 벽을 3개 세운 것을 원상복구

    return;
  }

  for (int i = start; i < none_list.size(); i++) {
    wall_list.push_back(none_list[i]);
    combi(i + 1, depth + 1, wall_list);
    wall_list.pop_back();
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      if (a[i][j] == 0) none_list.push_back({i, j});
      if (a[i][j] == 2) virus_list.push_back({i, j});
    }
  }

  combi(0, 0, wall_list);

  cout << ret << "\n";

  return 0;
}