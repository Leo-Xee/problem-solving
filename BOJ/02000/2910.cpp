/**
 * 문제: 빈도 정렬
 *
 * 시간 복잡도: O(NlogN)
 *
 * 문제 풀이
 * 1. 수열을 입력 받는다.
 *   1. 숫자:빈도로 구성된 Map(mp)을 구성한다.
 *   2. 숫자:순서로 구성된 Map(mp_first)을 구성한다.
 * 2. mp을 순회하여 {빈도 : 숫자}의 Pair의 결과 벡터(ret)를 구성한다.
 * 3. ret을 커스텀 비교 함수를 통해 정렬한다.
 *   1. 빈도가 다를 경우에는 빈도 내림차순로 정렬한다.
 *   2. 빈도가 같을 경우에는 순서 오름차순으로 정렬한다.
 * 4. ret을 순회하여 빈도만틈 숫자를 출력한다.
 */

#include <bits/stdc++.h>
using namespace std;

int n, c, a[1004];
map<int, int> mp, mp_first;  // mp = 숫자:빈도 수, mp_first = 숫자:나온순서
vector<pair<int, int>> ret;  // ret = {빈도수, 숫자}

// true면 a가 앞에 위치, false면 b가 앞에 위치
bool cmp(pair<int, int> a, pair<int, int> b) {
  if (a.first == b.first) {
    return mp_first[a.second] < mp_first[b.second];
  }
  return a.first > b.first;
}

int main() {
  cin >> n >> c;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mp[a[i]]++;

    if (mp_first[a[i]] == 0) {
      mp_first[a[i]] = i + 1;
    }
  }

  for (auto it : mp) {
    ret.push_back({it.second, it.first});
  }

  sort(ret.begin(), ret.end(), cmp);

  for (auto it : ret) {
    for (int i = 0; i < it.first; i++) {
      cout << it.second << " ";
    }
  }

  return 0;
}