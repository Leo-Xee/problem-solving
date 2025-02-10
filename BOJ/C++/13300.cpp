#include <bits/stdc++.h>
using namespace std;

int n, k, s, y, a[7], b[7], ret;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> k;

  for (int i = 0; i < n; i++) {
    cin >> s >> y;
    if (s) {
      a[y]++;
    } else {
      b[y]++;
    }
  }

  for (int it : a) {
    ret += it / k;
    if (it % k) ret++;
  }

  for (int it : b) {
    ret += it / k;
    if (it % k) ret++;
  }

  cout << ret;

  return 0;
}