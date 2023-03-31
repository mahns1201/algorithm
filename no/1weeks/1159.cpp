// 누가 선발인지 기억하기 쉽게 하기 위해 
// 성의 첫 글자가 같은 선수 5명을 선발하려고 한다. 
// 만약, 성의 첫 글자가 같은 선수가 5명보다 적다면, 
// 상근이는 내일 있을 친선 경기를 기권하려고 한다.
// 상근이는 내일 경기를 위해 뽑을 수 있는 성의 첫 글자를 모두 구해보려고 한다.

#include<bits/stdc++.h>
using namespace std;

string input;
int N;
int cnt[26];
int t = 0;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  char name[N];

  for (int i=0; i<N; i++) {
    cin >> input;
    name[i] = input.substr(0, 1)[0];
  }

  for (char a : name) cnt[a - 'a']++;
  
  for (int j=0; j<26; j++) {
    if (cnt[j] >= 5) {
      t++;
      cout << char(j + 97) << "";
    }
  }
  
  if (t == 0) {
    cout << "PREDAJA";
  }

  cout << "\n";
}