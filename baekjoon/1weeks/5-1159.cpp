// https://www.acmicpc.net/problem/1159

/*
	날짜: 2023-12-27
	횟수: 2
*/

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

// int n;
// int arr[30];
// string ret;

// int main() {
//     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//     cin >> n;
//     for (int i=0; i<n; i++) {
//         string s;
//         cin >> s;
//         arr[int(s[0])-97]++;
//     }

//     for (int i=0; i<26; i++) {
//         if (5 <= arr[i]) {
//             ret += char(i+97);
//         }
//     }

//     ret.size() ? cout << ret : cout << "PREDAJA";

//     return 0;
// }