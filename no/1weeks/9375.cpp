// https://www.acmicpc.net/problem/9375

#include <bits/stdc++.h>
using namespace std;

int P, C;
string thing, type;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  cin >> P;
  for (int i=0; i<P; i++) {
    cin >> C;

    map<string, int> li;
    for (int j=0; j<C; j++) {
      cin >> thing >> type;

      li[type]++;
    }
    
    long long ret = 1;
    for (auto it : li) {
      ret *= ((long long)it.second + 1);
    }
    
    cout << ret - 1 << "\n";
  }

  return 0;
}