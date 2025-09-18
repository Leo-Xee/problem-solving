/**
 * 문제: Z
 *
 * 시간 복잡도: O(N)
 *
 * 문제 풀이
 * 1. 2^N x 2^N 배열을 4개의 2^(N-1) x 2^(N-1) 영역으로 나눈다.
 * 2. 재귀를 수행한다.
 *    1.  N=0일 때, 0을 반환한다. (기저 사례)
 *    2. 목표 위치 (r, c)가 어느 사분면에 속하는지 확인한다.
 *      1. 좌상: 추가 없음
 *      2. 우상: half * half 추가
 *      3. 좌하: 2 * half * half 추가
 *      4. 우하: 3 * half * half 추가
 *    3. 상위 좌측 내에 위치 하지 않는 경우의 방문 차례에 대한 계산은 이미 half * half로 계산했으므로 r, c 값을 조정하여 재귀호출을 진행한다.
 * 3. 재귀 함수를 반환하는 값인 방문 횟수를 출력한다.
 */

#include <bits/stdc++.h>
using namespace std;

int n, r, c;

int go(int n, int r, int c) {
  if (n == 0) return 0;
  int half = pow(2, n - 1);

  // 상위 좌측
  if (r < half && c < half) {
    return go(n - 1, r, c);
  }
  // 상위 우측
  if (r < half && c >= half) {
    return half * half + go(n - 1, r, c - half);
  }
  // 하위 좌측
  if (r >= half && c < half) {
    return 2 * half * half + go(n - 1, r - half, c);
  }
  // 하위 우측
  return 3 * half * half + go(n - 1, r - half, c - half);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> r >> c;
  cout << go(n, r, c);

  return 0;
}