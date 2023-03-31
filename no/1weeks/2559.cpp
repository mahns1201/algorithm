// 문제가 길어서 링크 참조 https://www.acmicpc.net/problem/2559

#include <bits/stdc++.h>
using namespace std;

// prefix sum 구현 손에 익히자!
// 변수 선언 

int N, space;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  cin >> N >> space;
  int R = N - space + 1;
  int numbers[N], pSum[N+1], result[R];
  for (int i=0; i<N; i++) {
    cin >> numbers[i];
  }

  pSum[0] = numbers[0];
  for (int i=1; i<N; i++) {
    pSum[i] = pSum[i-1] + numbers[i];
  }

  result[0] = pSum[space-1];
  for (int j=1; j<R; j++) {
    result[j] = pSum[j+space-1] - pSum[j-1];
  }

  sort(result, result+R, greater<int>());

  cout << result[0] << "\n";

  return 0;
}

