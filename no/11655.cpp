// ROT13은 카이사르 암호의 일종으로 영어 알파벳을 13글자씩 밀어서 만든다.
// 예를 들어, "Baekjoon Online Judge"를 ROT13으로 암호화하면 "Onrxwbba Bayvar Whqtr"가 된다. 
// ROT13으로 암호화한 내용을 원래 내용으로 바꾸려면 암호화한 문자열을 다시 ROT13하면 된다. 
// 앞에서 암호화한 문자열 "Onrxwbba Bayvar Whqtr"에 다시 ROT13을 적용하면 "Baekjoon Online Judge"가 된다.

#include <bits/stdc++.h>
using namespace std;

string input;
char words[104];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  getline(cin, input);
  for(int i=0; i<input.size(); i++) {
    words[i] = input[i];
  }

  // 굳이 char words[104]에 안 넣고 그냥 하면 됨.
  for(int j=0; j<input.size(); j++) {
    int i = int(words[j]);
    int v = i + 13;
    if(65 <= i && i <= 90) {
      if (v > 90) v = v - 26;
    } else if(97 <= i && i <= 122) {
      if (v > 122) v = v - 26;
    } else v = v - 13;

    cout << char(v) << "";
  }
  cout << "\n";

  return 0;
}