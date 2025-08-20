/**
 * 문제: DFS와 BFS
 *
 * 시간 복잡도: O(MlogM)
 *
 * 문제 풀이
 * 1. 인접 리스트(adj) 기반으로 양방향 간선을 고려해서 입력을 받는다.
 * 2. 방문할 수 있는 정점이 여러 개인 경우에 작은 것부터 방문해야함으로 오름차순 정렬을 적용한다.
 * 3. DFS를 진행하고 최초 방문 시에 해당 정점을 결과 벡터(ret1)에 추가한다.
 * 4. 방문 배열(visited)을 초기화한다.
 * 5. BFS를 진행하고 최초 방문 시에 해당 정점을 결과 벡터(ret2)에 추가한다.
 * 6. ret1, re2를 순회하면서 출력한다.
 */

#include <bits/stdc++.h>
using namespace std;

vector<int> adj[10004], ret1, ret2;
int visited[10004];
int n, m, v, from, to;

void dfs(int here) {
  if (visited[here]) return;
  visited[here] = 1;
  ret1.push_back(here);
  for (int there : adj[here]) {
    if (visited[there]) continue;
    dfs(there);
  }
}

void bfs(int here) {
  queue<int> q;
  visited[here] = 1;
  q.push(here);

  while (q.size()) {
    int here = q.front();
    q.pop();
    ret2.push_back(here);
    for (int there : adj[here]) {
      if (visited[there]) continue;
      visited[there] = 1;
      q.push(there);
    }
  }
}

int main() {
  cin >> n >> m >> v;
  for (int i = 0; i < m; i++) {
    cin >> from >> to;
    adj[from].push_back(to);
    adj[to].push_back(from);
  }

  for (int i = 1; i <= n; i++) {
    sort(adj[i].begin(), adj[i].end());
  }

  dfs(v);
  fill(visited, visited + 10004, 0);
  bfs(v);

  for (int it : ret1) cout << it << " ";
  cout << "\n";
  for (int it : ret2) cout << it << " ";

  return 0;
}