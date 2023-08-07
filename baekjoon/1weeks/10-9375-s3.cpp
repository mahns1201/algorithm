// https://www.acmicpc.net/problem/9375

#include <bits/stdc++.h>
using namespace std;

int P, C;
string thing, type;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  cin >> P;
  for (int i=0; i<P; i++) {
    cin >> C;

    map<string, int> li;
    for (int j=0; j<C; j++) {
      cin >> thing >> type;

      li[type]++;
    }
    
    long long ret = 1;
    for (auto it : li) {
      ret *= ((long long)it.second + 1);
    }
    
    cout << ret - 1 << "\n";
  }

  return 0;
}

int N;
vector<int> ret;

void printV(vector<int> V) {
    for (auto i: V) {
        cout << i << "\n";
    }
}


/*
	날짜: 2023-08-07
	횟수: 2
  특이사항: 필요 없는 코드 삭제할 것.
*/
// int main() {
//     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//     cin >> N;

//     for (int i=0; i<N; i++) {
//         string temp, type;
//         map<string, int> cMap;
//         int M;
//         cin >> M;

//         for (int j=0; j<M; j++) {
//             cin >> temp >> type;
//             cMap[type]++;
//         }  
        
//         if (cMap.size() == 1) {
//             for (auto c: cMap) {
//                 ret.push_back(c.second);
//             }
//         } else {
//             int x=1;
//             for (auto c: cMap) {
//                 x *= (c.second+1);
//             }
//             x--;
//             ret.push_back(x);
//         }
//     }

//     printV(ret);

//     return 0;
// }