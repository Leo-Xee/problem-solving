/**
 * 문제: 인구 이동
 *
 * 시간 복잡도: O(N^4)
 *
 * 문제 풀이
 * 1. 인구 이동이 더 이상 일어나지 않을 때까지 반복한다.
 * 2. 각 반복에서 모든 나라를 탐색하며, 방문하지 않은 나라에서 BFS를 실행한다.
 * 3. BFS로 인접한 나라들 중 인구 차이가 L 이상 R 이하인 나라들을 찾아 연합을 구성한다.
 * 4. 연합이 2개 이상의 나라로 구성되면 연합의 모든 나라 인구를 평균값으로 업데이트한다.
 * 5. 한 번의 반복에서 인구 이동이 발생했다면 일수를 증가시키고 다시 반복한다.
 */

#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int n, l, r, sum, ret;
int a[54][54], visited[54][54];
vector<pair<int, int>> v;

void bfs(int y, int x) {
  queue<pair<int, int>> q;
  visited[y][x] = 1;
  q.push({y, x});

  v.push_back({y, x});  // 연합에 시작점 추가
  sum += a[y][x];       // 연합의 총 인구 수에 시작점 인구 수 추가

  while (q.size()) {
    tie(y, x) = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
      // 인구 차이가 l 이상 r 이하가 아니면 연합 불가
      if (abs(a[y][x] - a[ny][nx]) > r || abs(a[y][x] - a[ny][nx]) < l) continue;
      if (visited[ny][nx]) continue;

      visited[ny][nx] = 1;
      q.push({ny, nx});

      v.push_back({ny, nx});  // 연합에 추가
      sum += a[ny][nx];       // 연합의 총 인구 수에 추가
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> l >> r;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }

  // 인구 이동이 일어나지 않을 때까지 반복
  while (true) {
    bool is_moved = false;                // 인구 이동이 발생했는지 체크
    memset(visited, 0, sizeof(visited));  // 방문 배열 초기화

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (!visited[i][j]) {
          v.clear();  // 연합 벡터 초기화
          sum = 0;    // 연합 인구 수 초기화
          bfs(i, j);

          // 연합이 2개 이상의 나라로 구성되면 인구 이동 발생
          if (v.size() > 1) {
            is_moved = true;  // 인구 이동 발생 표시

            // 연합인 나라의 인구 수를 평균값으로 업데이트
            for (auto it : v) {
              a[it.first][it.second] = sum / v.size();
            }
          }
        }
      }
    }
    if (!is_moved) break;  // 인구 이동이 발생하지 않으면 종료
    ret++;                 // 인구 이동 일수 증가
  }

  cout << ret << "\n";

  return 0;
}