/**
 * 문제: 좌표 정렬하기
 *
 * 시간 복잡도: O(N * logN)
 *
 * 문제 풀이
 * 1. 커스텀 비교함수를 활용해서 x, y 좌표 기준 오름차순을 적용해 출력한다.
 */

#include <bits/stdc++.h>
using namespace std;

int n, x, y;
vector<pair<int, int>> v;

bool cmp(pair<int, int> a, pair<int, int> b) {
  if (a.first != b.first) return a.first < b.first;
  return a.second < b.second;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    v.push_back({x, y});
  }

  sort(v.begin(), v.end(), cmp);

  for (auto it : v) cout << it.first << " " << it.second << '\n';

  return 0;
}