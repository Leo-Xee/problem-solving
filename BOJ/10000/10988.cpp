#include <bits/stdc++.h>
using namespace std;

string a, b;
int main() {
  cin >> a;
  b.resize(a.size());
  reverse_copy(a.begin(), a.end(), b.begin());

  if (a == b)
    cout << 1;
  else
    cout << 0;

  return 0;
}