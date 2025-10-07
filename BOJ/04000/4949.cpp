/**
 * 문제: 균형잡힌 세상
 *
 * 시간 복잡도: O(N * M)
 * - N: 입력 줄의 수
 * - M: 각 줄의 길이
 *
 * 문제 풀이
 * 1. 스택 자료구조를 활용해서 대괄호와 중괄호의 매칭 여부를 체크한다.
 * 2. 입력 줄 자체가 '.'인 경우에는 반복문의 빠져나와 종료한다. (주의!)
 */

#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  while (getline(cin, s)) {
    stack<char> st;
    bool is_balanced = 1;

    if (s == ".") break;

    for (char c : s) {
      if (c == '[' || c == '(') st.push(c);

      if (c == ']') {
        if (st.empty() || st.top() != '[') {
          is_balanced = 0;
          break;
        }
        st.pop();
      }

      if (c == ')') {
        if (st.empty() || st.top() != '(') {
          is_balanced = 0;
          break;
        }
        st.pop();
      }
    }

    if (is_balanced && st.empty()) {
      cout << "yes" << "\n";
    } else {
      cout << "no" << "\n";
    }
  }

  return 0;
}