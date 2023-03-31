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

