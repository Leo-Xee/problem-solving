#include <bits/stdc++.h>
using namespace std;

// 1. 순열을 활용
int a[9];
int main() {
  for (int i = 0; i < 9; i++) {
    cin >> a[i];
  }

  sort(a, a + 9);

  do {
    int sum = 0;
    for (int i = 0; i < 7; i++) {
      sum += a[i];
    }

    if (sum == 100) break;
  } while (next_permutation(a, a + 9));

  for (int i = 0; i < 7; i++) {
    cout << a[i] << "\n";
  }

  return 0;
}

// 2. 반복문 활용
// int a, sum;
// pair<int, int> p;
// vector<int> v, ret;

// void solution() {
//   for (int i = 0; i < 9; i++) {
//     for (int j = 0; j < i; j++) {
//       if (sum - v[i] - v[j] == 100) {
//         p = {i, j};
//         return;
//       }
//     }
//   }
// }

// int main() {
//   for (int i = 0; i < 9; i++) {
//     cin >> a;
//     v.push_back(a);
//     sum += a;
//   }

//   solution();

//   for (int i = 0; i < 9; i++) {
//     if (i == p.first || i == p.second) continue;
//     ret.push_back(v[i]);
//   }

//   sort(ret.begin(), ret.end());
//   for (int i : ret) cout << i << "\n";

//   return 0;
// }

// 3. 재귀 활용
// int a[9];
// int n = 9, r = 7;
// void solve() {
//   int sum = 0;
//   for (int i = 0; i < r; i++) {
//     sum += a[i];
//   }

//   if (sum == 100) {
//     sort(a, a + 7);
//     for (int i = 0; i < r; i++) cout << a[i] << "\n";
//     exit(0);
//   }
// }

// void makePermutation(int n, int r, int depth) {
//   if (r == depth) {
//     solve();
//   }

//   for (int i = depth; i < n; i++) {
//     swap(a[i], a[depth]);
//     makePermutation(n, r, depth + 1);
//     swap(a[depth], a[i]);
//   }
//   return;
// }

// int main() {
//   for (int i = 0; i < n; i++) cin >> a[i];
//   makePermutation(n, r, 0);
//   return 0;
// }