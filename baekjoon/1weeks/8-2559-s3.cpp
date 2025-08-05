// https://www.acmicpc.net/problem/2559
// presum, 변수 선언 

#include <bits/stdc++.h>
using namespace std;


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

  sort(result, result+R, greater<int>()); // max 함수로 개선하자

  cout << result[0] << "\n";

  return 0;
}

/*
	날짜: 2023-08-07
	횟수: 2
*/
// #include <bits/stdc++.h>
// using namespace std;

// int N, K;
// int preSum[100004];
// vector<int> ret;

// int main() {
//     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//     cin >> N >> K;
    
//     int n;
//     for (int i=0; i<N; i++) {
//         cin >> n;
//         preSum[i+1] = preSum[i] + n;
//     }

//     for (int j=K; j<N+1; j++) {
//         ret.push_back(preSum[j] - preSum[j-K]);
//     }

//     sort(ret.begin(), ret.end(), greater<int>());
//     cout << ret[0] << "\n";

//     return 0;
// }

/*
	날짜: 2025-08-05
	횟수: 3
  특이사항: 모든 구간합이 음수일 수 있기 때문에 ret을 0으로 초기화 하면 오답이 된다.
*/
// #include <bits/stdc++.h>
// using namespace std;

// int n, k, t, ret = -987654321;
// int arr[100004];
// int main() {
//     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//     cin >> n >> k;

//     for (int i=1; i<n+1; i++) {
//         cin >> t;
//         arr[i] = t + arr[i-1];
//     }

//     for (int i=k; i<n+1; i++) {
//         ret = max(ret, arr[i] - arr[i-k]);
//     }

//     cout << ret << "\n";

//     return 0;
// }