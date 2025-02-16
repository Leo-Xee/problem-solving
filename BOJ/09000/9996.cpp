#include <bits/stdc++.h>
using namespace std;

int N, pos;
string pre, post, s, input, ret;
int main() {
  cin >> N;
  cin >> s;

  pos = s.find("*");
  pre = s.substr(0, pos);
  post = s.substr(pos + 1);

  // pre, post의 길이만큼 문자열을 앞위로 잘라서 일치하는지 확인
  for (int i = 0; i < N; i++) {
    cin >> input;

    if (input.size() < pre.size() + post.size()) {
      ret += "NE\n";
      continue;
    }

    if (input.substr(0, pre.size()) == pre &&
        input.substr(input.size() - post.size()) == post) {
      ret += "DA\n";
    } else {
      ret += "NE\n";
    }
  }

  cout << ret;
  return 0;
}
