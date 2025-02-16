#include <bits/stdc++.h>
using namespace std;

int N, M;  // N개 중 M개를 맞춰야함, 최대갑은 각각 10만
string s;
map<int, string> mp1;
map<string, int> mp2;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    cin >> s;
    mp1[i + 1] = s;
    mp2[s] = i + 1;
  }

  for (int i = 0; i < M; i++) {
    cin >> s;

    // atoi: 숫자 문자열을 숫자로 변환, 해당되지 않을 경우 0 반환
    // 입력이 문자일 경우
    if (atoi(s.c_str()) == 0) {
      cout << mp2[s] << "\n";
    } else {
      // 입력이 숫자일 경우
      cout << mp1[atoi(s.c_str())] << "\n";
    }
  }

  return 0;
}