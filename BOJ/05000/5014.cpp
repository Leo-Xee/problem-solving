/**
 * 문제: 스타트링크
 *
 * 시간 복잡도: O(F)
 *
 * 문제 풀이
 * 1. 강호가 위치한 S층을 시작해서 BFS를 수행한다.
 *   1. 현재 위치에서 위로 이동하는 층(u), 아래로 이동하는 층(d)를 계산하여 탐색을 진행한다.
 *   2. 건물의 층수를 이탈하거나 방문한 층 수인 경우에 skip한다.
 *   3. 거리 배열(dist)에 현재까지 진행된 거리를 갱신한다.
 * 2. 스타트링크가 위치한 층 수(g)에 방문하지 않은 경우 주어진 문자열, 방문한 경우 해당 층 수의 최솟값을 출력한다.
 */

#include <bits/stdc++.h>
using namespace std;

int f, s, g, u, d;
int dist[10000004], visited[10000004];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> f >> s >> g >> u >> d;

  queue<int> q;
  visited[s] = 1;
  q.push(s);

  while (q.size()) {
    int current = q.front();
    q.pop();
    for (int next : {current + u, current - d}) {
      if (next > f || next <= 0 || visited[next]) continue;
      visited[next] = 1;
      dist[next] = dist[current] + 1;
      q.push(next);
    }
  };

  if (!visited[g])
    cout << "use the stairs";
  else
    cout << dist[g];

  return 0;
}