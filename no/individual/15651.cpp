// https://www.acmicpc.net/problem/15651
// 2차 풀이
// #include <bits/stdc++.h>
// using namespace std;

// int N, M;

// void calc(vector<int> arr) {
  

//   if (arr.size() == M) {
//     for (int a: arr) cout << a << " ";
//     cout << "\n";
//     return;
//   }

//   for (int i=1; i<N+1; i++) {
//     arr.push_back(i);
//     calc(arr);
//     arr.pop_back();
//   }
// }

// int main() {
//   ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

//   cin >> N >> M;
//   calc({});

//   return 0;
// }

#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> result;
void rFn(int target, vector<int> result) {
  // cout << result.size() << target << "\n";
  // for (int j=0; j<result.size(); j++) {
  //   cout << result[j];
  // }
  // cout << "\n";

  // result.size()가 target과 같으면 출력한다.
  if (result.size() == target) {
    // cout << "종료" << "\n";
    for (int i=0; i<target; i++) {
      cout << result[i] << " ";
    }
      cout << "\n";
    return;
  }
  // 반복을 돌면서 numbers에 가장 앞에 것을 current에 저장한다.
  for (int j=1; j<N+1; j++) {
    // cout << "result.size: " << result.size() << " j: " << j << "\n";
    int current = j;
    result.push_back(current);
    // cout << "result: ";
    // for (int k=0; k<result.size(); k++) {
    //   cout << result[k];
    // }
    // cout << "\n";
    rFn(target, result);
    result.erase(result.end()-1);
    // cout << "result erase 실행!" << "\n";
    // for (int k=0; k<result.size(); k++) {
    //   cout << result[k];
    // }
    // cout << "\n";
  }
}

