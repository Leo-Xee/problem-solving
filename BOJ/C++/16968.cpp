#include <bits/stdc++.h>
using namespace std;

string s;
int cnt = 1;

int main() {
  cin >> s;

  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'd') {
      if (s[i - 1] == s[i]) {
        cnt *= 9;
      } else {
        cnt *= 10;
      }
    }

    if (s[i] == 'c') {
      if (s[i - 1] == s[i]) {
        cnt *= 25;
      } else {
        cnt *= 26;
      }
    }
  }

  cout << cnt;

  return 0;
}