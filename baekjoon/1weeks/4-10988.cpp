// 팰린드롬

#include<bits/stdc++.h>
using namespace std;


/*
	날짜: 2023-12-21
	횟수: 3
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