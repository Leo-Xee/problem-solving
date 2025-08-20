/**
 * 문제: 영역 구하기
 *
 * 시간 복잡도: O(MN)
 *
 * 문제 풀이
 * 1. 직사각형의 개수(k)만큼 순회한다.
 *   1. 좌측 하단(cx1, cy1)과 우측 상단(cx2, cy2)으로 이루어진 직사각형 영역을 맵(a)에 1로 표시한다. (좌표를 배열로 변환 시에 범위 주의!)
 * 2. a의 특정 좌표가 0이고 방문하지 않은 경우에 대하여 BFS를 수행한다.
 *   1. 특정 좌표를 방문할 때마다 분리된 영역의 넓이(area)를 1만큼 증가시키고 최종값을 반환한다.
 * 3. area의 개별 값들을 분리된 영역의 넓이를 모아둘 벡터(ret)에 추가한다.
 * 4. ret을 오름차순 정렬한다.
 * 5. ret의 길이와 각 요소를 출력한다.
 */

#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int m, n, k, cx1, cy1, cx2, cy2;
int a[104][104], visited[104][104];
vector<int> ret;

int bfs(int y, int x) {
  queue<pair<int, int>> q;
  visited[y][x] = 1;
  q.push({y, x});

  int area = 0;

  while (q.size()) {
    tie(y, x) = q.front();
    q.pop();
    area++;
    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (ny < 0 || ny >= m || nx < 0 || nx >= n) continue;
      if (!a[ny][nx] && !visited[ny][nx]) {
        visited[ny][nx] = 1;
        q.push({ny, nx});
      }
    }
  }

  return area;
}

int main() {
  cin >> m >> n >> k;

  for (int i = 0; i < k; i++) {
    cin >> cx1 >> cy1 >> cx2 >> cy2;

    for (int y = cy1; y < cy2; y++) {
      for (int x = cx1; x < cx2; x++) {
        a[y][x] = 1;
      }
    }
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (!a[i][j] && !visited[i][j]) {
        ret.push_back(bfs(i, j));
      }
    }
  }

  sort(ret.begin(), ret.end());
  cout << ret.size() << "\n";
  for (int it : ret) cout << it << " ";

  return 0;
}