/**
 * 문제: 치킨 배달
 *
 * 시간 복잡도: O(13CM x 100 x M)
 *
 * 문제 풀이
 * 1. 모든 집과 치킨집의 좌표를 저장한다.
 * 2. 치킨집 중에서 M개를 선택하는 모든 조합을 생성한다.
 * 3. 각 조합에 대해 도시의 치킨 거리를 계산해서 최솟값을 구하여 출력한다.
 *
 */

#include <bits/stdc++.h>
using namespace std;

int n, m, temp;
int ret = INT_MAX;                           // 도시의 치킨 거리 최솟값
vector<vector<int>> selected_chickens_list;  // 선택된 치킨집들의 인덱스 조합을 저장하는 리스트
vector<pair<int, int>> houses, chickens;     // 집과 치킨집의 좌표를 저장하는 벡터

void combi(int start, vector<int> v) {
  if (v.size() == m) {
    selected_chickens_list.push_back(v);  // 완성된 조합을 리스트에 추가
    return;
  }

  for (int i = start + 1; i < chickens.size(); i++) {
    v.push_back(i);
    combi(i, v);
    v.pop_back();
  }
  return;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> temp;
      if (temp == 1) houses.push_back({i, j});    // 집 좌표 저장
      if (temp == 2) chickens.push_back({i, j});  // 치킨집 좌표 저장
    }
  }

  vector<int> v;
  combi(-1, v);

  // 조합에 대해 도시의 치킨 거리 계산
  for (vector<int> selected_chickens : selected_chickens_list) {
    int city_dist = 0;  // 현재 조합에서의 도시의 치킨 거리

    // 모든 집에 대해 치킨 거리 계산
    for (pair<int, int> house : houses) {
      int min_dist = INT_MAX;  // 가장 가까운 치킨집까지의 거리

      // 선택된 치킨집들 중에서 가장 가까운 치킨집 찾기
      for (int idx : selected_chickens) {
        int dist_y = abs(house.first - chickens[idx].first);    // 세로 거리
        int dist_x = abs(house.second - chickens[idx].second);  // 가로 거리
        min_dist = min(min_dist, dist_y + dist_x);              // 최소 거리 갱신
      }
      city_dist += min_dist;
    }
    ret = min(ret, city_dist);  // 모든 조합 중 최소 도시 치킨 거리 갱신
  }

  cout << ret;

  return 0;
}