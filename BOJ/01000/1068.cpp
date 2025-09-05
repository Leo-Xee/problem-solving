/**
 * 문제: 트리
 *
 * 시간 복잡도: O(N)
 *
 * 문제 풀이
 * 1. 인접 리스트(adj) 기반으로 단방향 그래프를 구성한다.
 *   1. 부모 노드가 없는 경우에는 해당 노드가 루트 노드임을 변수(root)에 저장한다.
 * 2. 루트 노드부터 DFS를 수행한다.
 *   1. 다음 노드가 제거될 노드(target)이면 건너뛴다.
 *   2. 리프 노드의 개수를 구하기 위해서 해당 노드의 자식 노드 개수(child)를 1만큼 증가시킨다.
 *   3. 리프 노드인 경우에는 child가 0이므로 리프 노드의 개수인 1을 반환하고 함수를 종료한다.
 * 3. target와 root가 같으면 리프 노드의 개수가 없으므로 0을 출력한다.
 * 4. DFS를 수행한 최종 반환값인 리프 노드의 개수를 출력한다.
 */

#include <bits/stdc++.h>
using namespace std;

int n, target, parent, root;
vector<int> adj[54];

int dfs(int here) {
  int ret = 0;
  int child = 0;
  for (int there : adj[here]) {
    if (there == target) continue;
    ret += dfs(there);
    child++;
  }
  if (child == 0) return 1;

  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> parent;
    if (parent == -1) {
      root = i;
      continue;
    }
    adj[parent].push_back(i);
  }
  cin >> target;

  if (target == root) {
    cout << 0 << "\n";
  } else {
    cout << dfs(root) << "\n";
  }

  return 0;
}