#include <bits/stdc++.h>
using namespace std;

int n, p;
string a, b;
int main() {
  cin >> n;

  for (int i = 0; i < n; i++) {
    map<string, int> mp;
    cin >> p;

    for (int j = 0; j < p; j++) {
      cin >> a >> b;
      mp[b]++;
    }

    int ret = 1;
    for (auto it : mp) {
      ret *= it.second + 1;
    }
    ret--;
    cout << ret << "\n";
  }

  return 0;
}
