#include <bits/stdc++.h>
using namespace std;

string s, ret;
int N, cnt[26];
int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> s;
    cnt[s[0] - 97]++;
  }

  for (int i = 0; i < 26; i++) {
    if (cnt[i] >= 5) {
      ret += char(i + 97);
    }
  }

  if (ret.size() == 0) {
    cout << "PREDAJA";
  } else {
    cout << ret;
  }

  return 0;
}