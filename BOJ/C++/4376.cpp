#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  while (cin >> n) {
    ll ones = 1, ret = 1;

    while (true) {
      if (ones % n == 0) {
        cout << ret << '\n';
        break;
      } else {
        // ones = (ones % n * 10 % n) + 1;
        ones = (ones * 10) + 1;
        ones %= n;
        ret++;
      }
    }
  }

  return 0;
}