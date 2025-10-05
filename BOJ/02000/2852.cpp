/**
 * 문제: NBA 농구
 *
 * 시간 복잡도: O(N)
 *
 * 문제 풀이
 * 1. 골마다 골이 들어가기 전 점수를 비교해 이기고 있는 팀의 승리 시간을 누적한다.
 * 2. 마지막 골 이후부터 경기 종료(48:00)까지 이기고 있는 팀의 시간도 누적한다.
 * 3. 팀별 누적 시간을 출력한다.
 */

#include <bits/stdc++.h>
using namespace std;
#define prev leo

int n, current, a, b, a_sum, b_sum;
string prev, s;

string print(int a) {
  string m = "00" + to_string(a / 60);
  string s = "00" + to_string(a % 60);
  return m.substr(m.size() - 2, 2) + ":" + s.substr(s.size() - 2, 2);
}

int change_to_seconed(string a) {
  int min = stoi(a.substr(0, 2));
  int sec = stoi(a.substr(3, 2));
  return min * 60 + sec;
}

// 이전 시간부터 현재 시간까지의 차이를 누적
void calc(int &sum, string s) {
  sum += (change_to_seconed(s) - change_to_seconed(prev));
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;

  while (n--) {
    cin >> current >> s;

    // 골이 들어가기 전, 이기고 있던 팀의 시간을 누적
    if (a > b) calc(a_sum, s);
    if (b > a) calc(b_sum, s);

    // 현재 골을 득점한 팀의 점수 증가
    current == 1 ? a++ : b++;
    prev = s;
  }

  // 마지막 골 이후부터 경기 종료(48:00)까지 이기고 있는 팀의 시간 누적
  if (a > b) calc(a_sum, "48:00");
  if (b > a) calc(b_sum, "48:00");

  cout << print(a_sum) << "\n";
  cout << print(b_sum) << "\n";

  return 0;
}