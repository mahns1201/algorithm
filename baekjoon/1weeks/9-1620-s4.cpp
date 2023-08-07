// https://www.acmicpc.net/problem/1620

#include <bits/stdc++.h>
using namespace std;

int N, M;
string s, answer;
map<string, int> m;
string a[100004];
int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  cin >> N >> M;
  for (int i=0; i<N; i++) {
    cin >> s;

    m[s] = i+1;
    a[i+1] = s;
  }

  // 대답
  string answers[M];
  for (int j=0; j<M; j++) {
    cin >> answers[j];
  }
  
  for (string answer: answers) {
    if (atoi(answer.c_str()) == 0) {
      cout << m[answer] << "\n";
    } else {
    cout << a[atoi(answer.c_str())] << "\n";
    }
  }

  return 0;
}

/*
	날짜: 2023-08-07
	횟수: 2
  특이사항: 코드가 더 안 좋아짐. 다시 풀어보자.
*/
// #include <bits/stdc++.h>
// using namespace std;

// int N, M; // 1 <= N, M <= 100000;
// map<string, int> bookKeyString;
// map<int, string> bookKeyInt;
// vector<string> ret;

// void printV(vector<string> V) {
//     for (auto i: V) {
//         cout << i << "\n";
//     }
// }

// int main() {
//     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

//     cin >> N >> M;
//     for (int i=0; i<N; i++) {
//         string temp;
//         cin >> temp;
//         bookKeyString[temp] = i;
//         bookKeyInt[i] = temp;
//     }

//     for (int j=0; j<M; j++) {
//         string temp;
//         cin >> temp;
//         if (65 <= temp[0] && temp[0] <= 91) {
//             ret.push_back(to_string(bookKeyString[temp]+1));
//         } else ret.push_back(bookKeyInt[stoi(temp)-1]);
//     }
    
//     printV(ret);
    
//     return 0;
// }