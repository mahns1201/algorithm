// https://www.acmicpc.net/problem/10988
// 팰린드롭
// 문자열 뒤집기

#include<bits/stdc++.h>
using namespace std;


/*
	날짜: 2025-08-05
	횟수: 4
*/
string input;
int ret = 0;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> input;
  string prev = input;
  reverse(input.begin(), input.end());

  if (prev == input) {
    ret = 1;
  }
  
  cout << ret << "\n";
}

// string s;
// int main() {
//     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//     cin >> s;

//     if (s.size() == 1) {
//         cout << "1\n";
//         exit(0);
//     }

//     int si = 0;
//     int se = s.size() - 1;
    
//     while(true) {
//         if (si >= se) {
//             cout << "1\n";
//             exit(0);
//         }

//         if (s[si] != s[se]) {
//             cout << "0\n";
//             exit(0);
//         }

//         si++;
//         se--;
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// string s;
// int main() {
//     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//     cin >> s;

//     string reversed = s;
//     reverse(s.begin(), s.end());
    
//     if (reversed == s) {
//         cout << 1 << "\n";
//     } else cout << 0 << "\n";
    
//     return 0;
// }