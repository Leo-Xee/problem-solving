#include <bits/stdc++.h>
using namespace std;

int a, b, c;
int t[104];
int ret;
int main() {
  cin >> a >> b >> c;

  for (int i = 0; i < 3; i++) {
    int start, end;
    cin >> start >> end;

    for (int i = start; i < end; i++) {
      t[i]++;
    }
  }

  for (auto i : t) {
    if (i == 1) ret += a * i;
    if (i == 2) ret += b * i;
    if (i == 3) ret += c * i;
  }

  cout << ret;

  return 0;
}