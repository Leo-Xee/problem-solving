#include <bits/stdc++.h>
using namespace std;

// 대문자 65 - 90
// 소문자 97 - 122
string s;
int main() {
  getline(cin, s);

  for (int i = 0; i < s.size(); i++) {
    // 대문자
    if (s[i] >= 65 && s[i] <= 90) {
      if (s[i] + 13 > 90) {
        s[i] -= 13;
      } else {
        s[i] += 13;
      }
    }

    // 소문자
    if (s[i] >= 97 && s[i] <= 122) {
      if (s[i] + 13 > 122) {
        s[i] -= 13;
      } else {
        s[i] += 13;
      }
    }
  }

  cout << s;

  return 0;
}