/**
 * 문제: 연결 요소의 개수
 *
 * 시간 복잡도: O(M+N)
 *
 * 문제 풀이
 * 1. 인접 리스트(adj) 기반으로 무방향 간선을 고려해서 입력을 받는다.
 * 2. 모든 정점에 대해서 DFS를 수행한다.
 * 3. 특정 정점을 최초로 방문할 때마다 연결 요소의 개수(cnt)을 1만큼 증가시킨다.alignas
 * 4. cnt를 출력한다.
 */

#include <bits/stdc++.h>
using namespace std;

int n, m, from, to, visited[1004], cnt;
vector<int> adj[1004];

void dfs(int here) {
  visited[here] = 1;
  for (int there : adj[here]) {
    if (!visited[there]) {
      dfs(there);
    }
  }
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> from >> to;
    adj[from].push_back(to);
    adj[to].push_back(from);
  }

  for (int i = 1; i <= n; i++) {  // 범위 실수 주의!
    if (!visited[i]) {
      dfs(i);
      cnt++;
    }
  }

  cout << cnt << "\n";

  return 0;
}