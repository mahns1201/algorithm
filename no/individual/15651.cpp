// https://www.acmicpc.net/problem/15651
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
