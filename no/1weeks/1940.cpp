#include <bits/stdc++.h>
using namespace std;

int N, M, ret;
int li[10000004];
int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  cin >> N >> M;
  int n;
  for(int i=0; i<N; i++) {
    cin >> n;
    li[i] = n;
  }


  // 이렇게 하지말고 2중 for문 사용해서 nCr 구현 해보기 (i만 사용하면 됨)
  // 다른 방법으로 조합 구현 확인.
  int temp=0;
  for (int j=0; j<N; j++) {
    temp += 1;
    for (int k=temp; k<N; k++){
      cout << j << "+" << k << ": " << li[j] + li[k] << "\n";

      if (li[j] + li[k] == M) {
        ret += 1;
      }
    }
  }

  cout << ret << "\n";

  return 0;
}