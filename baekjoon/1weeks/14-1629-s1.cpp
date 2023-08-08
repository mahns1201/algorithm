// https://www.acmicpc.net/problem/1629

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int A, B, c;
ll calc(ll a, ll b) { 
  if(b==1) return a % c;

  ll ret = calc(a, b/2);
  ret = (ret * ret) % c;
  if(b&1) ret = (ret * a) % c;

  return ret;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  
  cin >> A >> B >> c;

  if (c == 1) {
    cout << 0 << "\n";
    exit(0);
  } 

  if (A % c == 0) {
    cout << 0 << "\n"; 
    exit(0);
  }

  cout << calc(A, B) << "\n";

  return 0;
}

/*
	날짜: 2023-08-08
	횟수: 2
  특이사항: 한 번 더 풀어보자.
*/