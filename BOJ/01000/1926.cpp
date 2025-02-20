#include <bits/stdc++.h>
using namespace std;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int n, m, a[504][504], visited[504][504], cnt, ret;

void dfs(int y, int x, int& temp) {
  visited[y][x] = 1;
  temp++;

  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
    if (!a[ny][nx] || visited[ny][nx]) continue;
    dfs(ny, nx, temp);
  }

  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 1 && !visited[i][j]) {
        int temp = 0;
        dfs(i, j, temp);
        cnt++;
        ret = max(temp, ret);
      }
    }
  }

  cout << cnt << "\n" << ret << "\n";

  return 0;
}