#include <bits/stdc++.h>
using namespace std;

string s, ret;
int cnt[200], fail;
char mid;
int main() {
  cin >> s;
  for (char it : s) cnt[it]++;

  for (int i = 'Z'; i >= 'A'; i--) {
    if (cnt[i]) {
      if (cnt[i] % 2 == 1) {
        fail++;
        mid = char(i);
        // 중앙에 넣을 알파벳 1개 소모
        cnt[i]--;
      }

      if (fail == 2) break;

      // 알파벳을 2개씩 소모
      for (int j = 0; j < cnt[i]; j += 2) {
        ret = char(i) + ret;
        ret += char(i);
      }
    }
  }

  if (mid) {
    ret.insert(ret.begin() + ret.size() / 2, mid);
  }

  if (fail == 2) {
    cout << "I'm Sorry Hansoo\n";
  } else {
    cout << ret << "\n";
  }

  return 0;
}

// cin >> s;
// for(char a : s)cnt[a]++;
// for(int i = 'Z'; i >= 'A'; i--){
// 	if(cnt[i]){
// 		if(cnt[i] & 1){
// 			mid = char(i);flag++;
// 			cnt[i]--;
// 		}
// 		if(flag == 2)break;
// 		for(int j = 0; j < cnt[i]; j += 2){
// 			ret = char(i) + ret;
// 			ret += char(i);
// 		}
// 	}
// }
// if(mid)ret.insert(ret.begin() + ret.size() / 2, mid);
// if(flag == 2)cout << "I'm Sorry Hansoo\n";
// else cout << ret << "\n";

// 시간초과
// string v, s;
// bool found;
// int main() {
//   cin >> s;

//   for (int i = 0; i < s.size(); i++) {
//     v.push_back(s[i]);
//   }

//   sort(v.begin(), v.end());

//   do {
//     string a, b;

//     for (auto it : v) a.push_back(it);

//     b.resize(a.size());
//     reverse_copy(a.begin(), a.end(), b.begin());

//     if (a == b) {
//       found = true;
//       cout << a;
//       break;
//     }
//   } while (next_permutation(v.begin(), v.end()));

//   if (!found) {
//     cout << "I'm Sorry Hansoo";
//   }

//   return 0;
// }