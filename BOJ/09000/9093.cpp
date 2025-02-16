#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int t;

vector<string> split(string& input, string delimiter) {
  vector<string> ret;
  auto start = 0;
  auto end = input.find(delimiter);
  while (end != string::npos) {
    ret.push_back(input.substr(start, end - start));
    start = end + delimiter.size();
    end = input.find(delimiter, start);
  }
  ret.push_back(input.substr(start));
  return ret;
}

int main() {
  cin >> t;
  string bf;
  getline(cin, bf);

  while (t--) {
    string s;
    getline(cin, s);

    vector<string> v = split(s, " ");

    for (auto it : v) {
      reverse(it.begin(), it.end());
      cout << it << " ";
    }
    cout << '\n';
  }

  return 0;
}