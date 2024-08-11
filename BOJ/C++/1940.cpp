#include <bits/stdc++.h>
using namespace std;

// int n, m, cnt;
// int a[15004];
// int main() {
//   ios_base::sync_with_stdio(false);
//   cin.tie(NULL);

//   cin >> n >> m;

//   for (int i = 0; i <= n; i++) {
//     cin >> a[i];
//   }

//   for (int i = 0; i < n; i++) {
//     for (int j = i + 1; j < n; j++) {
//       if (a[i] + a[j] == m) cnt++;
//     }
//   }

//   cout << cnt << '\n';

//   return 0;
// }

// 재귀 활용
int n, m, a[15004], cnt;

void combi(int start, vector<int>& v) {
  if (v.size() == 2) {
    int b = a[v[0]];
    int c = a[v[1]];
    if (b + c == m) cnt++;
    return;
  }

  for (int i = start + 1; i < n; i++) {
    v.push_back(i);
    combi(i, v);
    v.pop_back();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<int> v;
  combi(-1, v);
  cout << cnt << '\n';
  return 0;
}