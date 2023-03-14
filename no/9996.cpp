// 패턴은 알파벳 소문자 여러 개와 별표(*) 하나로 이루어진 문자열이다.
// 파일 이름이 패턴에 일치하려면, 패턴에 있는 별표를 알파벳 소문자로 이루어진 
// 임의의 문자열로 변환해 파일 이름과 같게 만들 수 있어야 한다. 별표는 빈 문자열로 바꿀 수도 있다. 
// 예를 들어, "abcd", "ad", "anestonestod"는 모두 패턴 "a*d"와 일치한다. 하지만, "bcd"는 일치하지 않는다.
// 패턴과 파일 이름이 모두 주어졌을 때, 각각의 파일 이름이 패턴과 일치하는지 아닌지를 구하는 프로그램을 작성하시오.

#include <bits/stdc++.h>
using namespace std;

int N;
string pattern;

vector<string> split(string input, string delimiter) { 
  vector<string> ret;
  long long pos = 0;
  string token = "";
  while ((pos = input.find(delimiter)) != string::npos) { 
    token = input.substr(0, pos); 
    ret.push_back(token);
    input.erase(0, pos + delimiter.length());
  } 
  ret.push_back(input); 
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> pattern;
  string words[N];
  for(int i=0; i<N; i++) {
    cin >> words[i];
  }
  // split을 구현하지 말고 index로 처리하는 게 더 효과적이다.
  // String.find를 사용하면 된다.
  vector<string> p = split(pattern, "*");

  for(string word : words) {
    if(word.size() < p[0].size() + p[1].size()) {
      cout << "NE" << "\n";
      continue;
    }
    string first = word.substr(0, p[0].size());
    string last = word.substr(word.size()-p[1].size());

    if (first == p[0] && last == p[1]) cout << "DA" << "\n";
    else cout << "NE" << "\n";
  }
  

  return 0;
}