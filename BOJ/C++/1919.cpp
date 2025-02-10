#include <bits/stdc++.h>
using namespace std;

int cnt[26], ret;
string a, b;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> a >> b;

  for (char c : a) cnt[c - 'a']++;
  for (char c : b) cnt[c - 'a']--;

  for (int it : cnt) {
    if (it != 0) ret += abs(it);
  }

  cout << ret;

  return 0;
}