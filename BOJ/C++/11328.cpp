#include <bits/stdc++.h>
using namespace std;

int n;
string a, b;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  while (n--) {
    cin >> a >> b;

    int cnt[26] = {};
    bool f = true;

    for (char c : a) cnt[c - 'a']++;
    for (char c : b) cnt[c - 'a']--;

    for (int i = 0; i < 26; i++) {
      if (cnt[i] != 0) f = false;
    }

    if (f)
      cout << "Possible\n";
    else
      cout << "Impossible\n";
  }

  return 0;
}