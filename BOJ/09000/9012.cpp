#include <bits/stdc++.h>
using namespace std;

int t;

int main() {
  cin >> t;

  while (t--) {
    string s;
    stack<char> st;
    cin >> s;

    for (int i = 0; i < s.size(); i++) {
      if (st.empty()) {
        st.push(s[i]);
      } else {
        if (st.top() == '(' && s[i] == ')') {
          st.pop();
        } else {
          st.push(s[i]);
        }
      }
    }

    if (st.empty()) {
      cout << "YES" << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }

  return 0;
}