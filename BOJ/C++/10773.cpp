#include <bits/stdc++.h>
using namespace std;

int k, a, ret;
stack<int> st;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> k;

  while (k--) {
    cin >> a;

    if (a) {
      st.push(a);
    } else {
      if (st.size() != 0) st.pop();
    }
  }

  while (st.size() != 0) {
    ret += st.top();
    st.pop();
  }

  cout << ret;

  return 0;
}