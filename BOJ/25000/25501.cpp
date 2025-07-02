/**
 * 문제: 재귀의 귀재
 *
 * 시간 복잡도: O(N)
 * 공간 복잡도: O(N)
 *
 */

#include <bits/stdc++.h>
using namespace std;

int n, cnt;
char s[1004];

int recursion(const char *s, int l, int r) {
  cnt++;

  if (l >= r)
    return 1;
  else if (s[l] != s[r])
    return 0;
  else
    return recursion(s, l + 1, r - 1);
}

int isPalindrome(const char *s) { return recursion(s, 0, strlen(s) - 1); }

int main() {
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> s;
    cout << isPalindrome(s) << " " << cnt << '\n';
    cnt = 0;
  }

  return 0;
};