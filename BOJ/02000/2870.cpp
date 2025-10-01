/**
 * 문제: 수학 문제
 *
 * 시간 복잡도: O(N * M + K log K)
 * - N: 문자열 개수
 * - M: 각 문자열 길이
 * - K: 추출된 숫자 개수
 *
 * 문제 풀이:
 * 1. 각 문자열을 순회하며 연속된 숫자 부분을 추출한다.
 * 2. 추출한 숫자에서 앞의 0들을 제거한다. (단, "000"인 경우 "0"으로 처리)
 * 3. 모든 숫자를 길이 기준으로 정렬한다. (길이가 같으면 사전순)
 * 4. 결과를 출력한다.
 */

#include <bits/stdc++.h>
using namespace std;

int n;
string s, ret;
vector<string> v;

void remove_zero() {
  // 문자 0을 모두 제거
  while (true) {
    if (ret.size() && ret.front() == '0') {
      ret.erase(ret.begin());
    } else {
      break;
    }
  }

  if (!ret.size()) ret = '0';  // 추출된 값이 '0' 인 경우 대응
  v.push_back(ret);            // 검증된 추출값을 결과 벡터에 추가
  ret = "";
}

// 숫자 문자열 비교: 길이 우선, 길이가 같으면 사전순
bool cmp(string a, string b) {
  if (a.size() == b.size()) return a < b;
  return a.size() < b.size();
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> s;

    for (int j = 0; j < s.size(); j++) {
      if (isdigit(s[j])) {
        ret += s[j];  // 숫자를 추출
      } else {
        if (ret.size()) remove_zero();  // 숫자가 아닌 문자이면 추출한 값 검증
      }
    }

    if (ret.size()) remove_zero();  // 문자열의 마지막 문자가 숫자인 경우 대응
  }

  sort(v.begin(), v.end(), cmp);  // 커스텀 비교 함수로 정렬

  for (string it : v) cout << it << "\n";

  return 0;
}