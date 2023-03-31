// https://www.acmicpc.net/problem/4375

#include <bits/stdc++.h>
using namespace std;

int N, ret;
long long a;
void check() {
  if (N ==1) {
    cout << 1 << "\n"; 
    return;
  } else if (a % N == 0) {
    cout << ret << "\n"; 
    return;
  } 
  else {
    a = a * 10 + 1;
    a %= N;
    ret++;
    check();
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  
  while (scanf("%d", &N) != EOF) {
    a = 11;
    ret = 2;
    check();
  }
  

  return 0;
}

