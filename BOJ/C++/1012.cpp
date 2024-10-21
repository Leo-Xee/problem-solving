#include <bits/stdc++.h>
using namespace std;

const int max_len = 51;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int t, m, n, k, ret, x, y, a[max_len][max_len], visited[max_len][max_len];

void dfs(int y, int x) {
  visited[y][x] = 1;

  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
    if (a[ny][nx] == 0 || visited[ny][nx]) continue;
    dfs(ny, nx);
  }
}

int main() {
  cin >> t;

  for (int i = 0; i < t; i++) {
    memset(a, 0, sizeof(a));
    memset(visited, 0, sizeof(visited));
    ret = 0;
    cin >> m >> n >> k;

    for (int j = 0; j < k; j++) {
      cin >> x >> y;
      a[y][x] = 1;
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (a[i][j] == 1 && !visited[i][j]) {
          dfs(i, j);
          ret++;
        }
      }
    }

    cout << ret << '\n';
  }

  return 0;
}