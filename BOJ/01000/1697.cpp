#include <bits/stdc++.h>
using namespace std;

int n, k, vis[100004];
queue<int> q;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> k;

  fill(vis, vis + 100004, -1);
  vis[n] = 0;
  q.push(n);

  while (vis[k] == -1) {
    int here = q.front();
    q.pop();

    for (int there : {here - 1, here + 1, here * 2}) {
      if (there < 0 || there > 100000) continue;
      if (vis[there] != -1) continue;
      vis[there] = vis[here] + 1;
      q.push(there);
    }
  }

  cout << vis[k];

  return 0;
}