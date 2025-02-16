#include <bits/stdc++.h>
using namespace std;

int n, m, ret;
deque<int> dq;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;

  for (int i = 1; i <= n; i++) dq.push_back(i);

  while (m--) {
    int a;
    cin >> a;

    int idx = find(dq.begin(), dq.end(), a) - dq.begin();

    while (dq.front() != a) {
      if (idx <= dq.size() / 2) {
        dq.push_back(dq.front());
        dq.pop_front();
      } else {
        dq.push_front(dq.back());
        dq.pop_back();
      }
      ret++;
    }
    dq.pop_front();
  }

  cout << ret;

  return 0;
}