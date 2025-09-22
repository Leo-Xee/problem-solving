/**
 * 문제: 웰컴 키트
 *
 * 시간 복잡도: O(N)
 *
 * 문제 풀이
 * 1. 셔츠 사이즈 배열(shirts)를 순회한다.
 *   1. 사이즈별 셔츠 개수(shirt)를 티셔츠 묶음 수(t)로 나눈 몫을 티셔츠의 최소 묶음 개수(min_shirt_bundle)에 누적한다.
 *   2. shirt / t의 값이 0일 경우에는 추가 묶음이 필요하므로 min_shirt_bundle에 +1을 추가한다.
 * 2. min_shirt_bundle를 출력한다.
 * 3. 참가자 수(n)를 펜 묶음 수(p)로 나눈 몫과 나머지를 출력한다.
 */

#include <bits/stdc++.h>
using namespace std;

int n, t, p;
int shirts[6];
int min_shirt_bundle;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 0; i < 6; i++) cin >> shirts[i];
  cin >> t >> p;

  for (int shirt : shirts) {
    if (shirt % t != 0) min_shirt_bundle += 1;
    min_shirt_bundle += shirt / t;
  }

  cout << min_shirt_bundle << "\n";
  cout << n / p << " " << n % p << "\n";

  return 0;
}
