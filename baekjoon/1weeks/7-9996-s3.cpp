// https://www.acmicpc.net/problem/9996
// 문자열 찾기, 문자열 뒤집기

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


/*
	날짜: 2023-08-01
	횟수: 2
*/
// #include <bits/stdc++.h>
// using namespace std;

// int N;
// string I, pattern, s, e;
// vector<string> pat, ret;

// int main() {
//     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
//     cin >> N >> pattern;

//     int pos = pattern.find('*');

//     s = pattern.substr(0, pos);
//     e = pattern.substr(pos+1);
    
//     for (int i=0; i<N; i++) {
//         cin >> I;

//         if (s.length() + e.length() > I.length()) cout << "NE\n";
//         else if (s == I.substr(0, s.length()) && e == I.substr(I.length() - e.length(), I.length())) {
//             cout << "DA\n";
//         } 
//         else cout << "NE\n";
//     }

//     // for (auto r: ret) {
//     //     cout << r << "\n";
//     // }

//     return 0;
// }

/*
	날짜: 2023-12-27
	횟수: 3
  특이사항: 예외 생각 조금 더 해보자.
*/
// const char delimeter = '*';
// int n;
// string pattern, s; 
// vector<string> ret;

// void printV(vector<string> V) {
//     for (auto i: V) {
//         cout << i << "\n";
//     }
// }

// int main() {
//     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//     cin >> n >> pattern;
//     string front = pattern.substr(0, pattern.find(delimeter));
//     string back = pattern.substr(pattern.find(delimeter)+1, pattern.size());
//     for (int i=0; i<n; i++) {
//         cin >> s;

//         if (s.size() < front.size() + back.size()) {
//             ret.push_back("NE");
//             continue;
//         }
        
//         string t_front = s.substr(0, front.size());
//         string t_back = s.substr(s.size()-back.size(), s.size());

//         if (front == t_front && back == t_back) ret.push_back("DA");
//         else ret.push_back("NE");
//     }

//     printV(ret);

//     return 0;
// }