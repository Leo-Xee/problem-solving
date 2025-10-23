/**
 * 문제: 뮤탈리스크
 *
 * 시간 복잡도: O(60^3)
 *
 * 문제 풀이
 * 1. 뮤탈리스크의 공격 순서에 따라 6가지 경우의 수가 존재한다.
 * 2. SCV 3대의 체력을 3차원 좌표 (a, b, c)로 보고 BFS를 수행한다.
 * 3. 각 상태에서 6가지 공격 패턴을 모두 시도하여 다음 상태로 이동한다.
 * 4. 모든 SCV의 체력이 0이 되는 (0, 0, 0) 상태까지의 최소 공격 횟수를 구한다.
 */

#include <bits/stdc++.h>
using namespace std;

int n, scv[3];
int map[64][64][64], visited[64][64][64];
int attacks[6][3] = {
    {9, 3, 1}, {9, 1, 3}, {3, 9, 1}, {3, 1, 9}, {1, 3, 9}, {1, 9, 3},
};

// 유사 튜플 구조체를 정의
struct Tuple {
  int a, b, c;
};

int bfs(int a, int b, int c) {
  visited[a][b][c] = 1;
  queue<Tuple> q;
  q.push({a, b, c});

  while (q.size()) {
    int a = q.front().a;
    int b = q.front().b;
    int c = q.front().c;
    q.pop();

    for (int i = 0; i < 6; i++) {
      int na = max(0, a - attacks[i][0]);
      int nb = max(0, b - attacks[i][1]);
      int nc = max(0, c - attacks[i][2]);

      if (visited[na][nb][nc]) continue;
      visited[na][nb][nc] = visited[a][b][c] + 1;
      q.push({na, nb, nc});
    }
  }
  return visited[0][0][0] - 1;
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  cin >> scv[0] >> scv[1] >> scv[2];
  cout << bfs(scv[0], scv[1], scv[2]) << "\n";

  return 0;
}