#include <bits/stdc++.h>
using namespace std;

int n, k, Y, M;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  while (n--) {
    cin >> k;

    Y += (k / 30 + 1) * 10;
    M += (k / 60 + 1) * 15;
  }

  if (Y > M) {
    cout << "M " << M;
  }

  if (Y < M) {
    cout << "Y " << Y;
  }

  if (Y == M) {
    cout << "Y M " << M;
  }

  return 0;
}