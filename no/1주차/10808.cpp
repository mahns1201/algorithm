// 알파벳 소문자로만 이루어진 단어 S가 주어진다. 
// 각 알파벳이 단어에 몇 개가 포함되어 있는지 구하는 프로그램을 작성하시오.

#include <bits/stdc++.h>
using namespace std;

string input;
int cnt[26];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> input;
  for (char a : input) cnt[a - 'a']++;
  for (int i : cnt) cout << i << " ";
  cout << "\n";
  
  return 0;
}