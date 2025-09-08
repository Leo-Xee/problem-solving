/**
 * 문제: 효율적인 해킹
 *
 * 시간 복잡도: O(N × (N + M))
 *
 * 문제 풀이
 * 1. B를 해킹하면 A를 해킹할 수 있기 때문에 B에서 A로 가는 단방향 그래프를 구성한다.
 * 2. 가장 작은 컴퓨터 번호인 1부터 순회하면서 DFS를 수행한다.
 *   1. 각 정점별로 연결된 정점의 개수를 구해야하기 때문에 방문 배열(visited)를 초기화한다.
 *   2. 연결된 정점 개수를 반환하여 정점 개수 배열(ret)에 추가한다. (참고로, 인덱스는 컴퓨터 번호를 의미함.)
 *   3. 해킹할 수 있는 컴퓨터의 최대값(max_cnt)를 갱신한다.
 * 3. ret을 순회하면서 max_cnt인 경우의 인덱스를 출력한다. (이미 오름차순으로 정렬된 상태임.)
 */

#include <bits/stdc++.h>
using namespace std;

int n, m, from, to, max_cnt;
int visited[10004], ret[10004];
vector<int> adj[10004];

int dfs(int here) {
  visited[here] = 1;
  int cnt = 1;
  for (int there : adj[here]) {
    if (!visited[there]) {
      visited[there] = 1;
      cnt += dfs(there);
    }
  }
  return cnt;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> from >> to;
    adj[to].push_back(from);
  }

  for (int i = 1; i <= n; i++) {
    fill(&visited[0], &visited[0] + 10004, 0);
    ret[i] = dfs(i);
    max_cnt = max(max_cnt, ret[i]);
  }
  for (int i = 1; i <= n; i++) {
    if (ret[i] == max_cnt) cout << i << " ";
  }

  return 0;
}