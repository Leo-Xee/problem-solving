/**
 * 문제: 비밀번호 발음하기
 *
 * 시간 복잡도: O(T)
 *
 *
 * 문제 풀이
 * 1. 테스트 케이스를 순회한다.
 *   1. end를 입력 받으면 순회를 종료한다.
 *   2. 조건에 따른 플래그 변수를 정의한다.
 *   3. 문자열을 순회한다.
 *     1. 해당 문자가 모음이면 vowel_count를 1 증가, consonant_count를 0으로 리셋, is_include_vowel를 1로 지정한다.
 *     2. 해당 문자가 자음이면 consonant_count를 1 증가, vowel_count를 0으로 리셋한다.
 *     3. 모음이나 자음이 3개 연속으로 위치할 경우에는 실패 플래그(is_fail)을 true로 변경한다.
 *     4. 직전 문자와 현재 문자가 연속적으로 위치하거나 ee와 oo가 아닌 경우에 is_fail를 true로 변경한다.
 *   4. 모음이 하나도 포함되지 않은 경우에는 is_fail를 ture로 변경한다.
 *   5. is_fail 값에 따라 주어진 문장을 출력한다.
 */

#include <bits/stdc++.h>
using namespace std;

string s;

bool isVowel(int code) {
  return (code == 'a' || code == 'e' || code == 'i' || code == 'o' || code == 'u');
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  while (true) {
    bool is_fail = 0;
    bool is_include_vowel = 0;
    int consonant_count = 0;
    int vowel_count = 0;
    int prev = -1;

    cin >> s;
    if (s == "end") break;

    for (int i = 0; i < s.size(); i++) {
      int code = s[i];

      // 1번, 2번 조건 체크
      if (isVowel(code)) {
        vowel_count++;
        consonant_count = 0;
        is_include_vowel = 1;
      } else {
        consonant_count++;
        vowel_count = 0;
      }

      if (vowel_count == 3 || consonant_count == 3) is_fail = 1;

      // 3번 조건 체크
      if (i >= 1 && (prev == code) && (code != 'e' && code != 'o')) {
        is_fail = 1;
      }
      prev = code;
    }

    if (!is_include_vowel) is_fail = 1;
    if (is_fail) {
      cout << "<" << s << ">" << " is not acceptable.\n";
    } else {
      cout << "<" << s << ">" << " is acceptable.\n";
    }
  }

  return 0;
}