#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int m, n, a[1004][1004], vis[1004][1004], ret;
bool fail = false;
queue<pair<int, int>> q;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> m >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];

      if (a[i][j] == 1) {
        q.push({i, j});
      }

      if (a[i][j] == 0) {
        vis[i][j] = -1;
      }
    }
  }

  while (q.size()) {
    int y, x;
    tie(y, x) = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
      if (a[ny][nx] == -1 || vis[ny][nx] >= 0) continue;
      vis[ny][nx] = vis[y][x] + 1;
      q.push({ny, nx});
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (vis[i][j] == -1) {
        fail = true;
      }
      ret = max(ret, vis[i][j]);
    }
  }

  if (fail)
    cout << -1;
  else
    cout << ret;

  return 0;
}