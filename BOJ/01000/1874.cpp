#include <bits/stdc++.h>
using namespace std;

int n, cnt = 1;
stack<int> st;
string ret;
bool isPossible = true;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  while (n--) {
    int a;
    cin >> a;
    while (cnt <= a) {
      st.push(cnt);
      ret += "+\n";
      cnt++;
    }

    if (st.top() == a) {
      st.pop();
      ret += "-\n";
    } else {
      isPossible = false;
      break;
    }
  }

  if (isPossible) {
    cout << ret;
  } else {
    cout << "NO\n";
  }

  return 0;
}