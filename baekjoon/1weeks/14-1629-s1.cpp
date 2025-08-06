// https://www.acmicpc.net/problem/1629
// (a+b) % c = (a%c + b%c) % c
// (a×b) % c = ((a%c) × (b%c)) % c
// (a−b) % c = ((a%c) − (b%c) + c) % c

/*
    날짜: 2025-08-06
    횟수: 3
    특이사항: 분할정복과 정수론 생각하며 다시 풀어보자.
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a, b, c;

ll calc(ll n) {
    if (n == 1) {
        return a % c;
    }

    ll ret = calc(n/2);
    ll result = ret * ret % c;

    if (n%2 == 1) {
        result *= a % c;
    }
    
    return result % c;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> a >> b >> c;

    cout << calc(b) << "\n";

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;

// int A, B, c;
// ll calc(ll a, ll b) { 
//   if(b==1) return a % c;

//   ll ret = calc(a, b/2);
//   ret = (ret * ret) % c;
//   if(b&1) ret = (ret * a) % c;

//   return ret;
// }

// int main() {
//   ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  
//   cin >> A >> B >> c;

//   if (c == 1) {
//     cout << 0 << "\n";
//     exit(0);
//   } 

//   if (A % c == 0) {
//     cout << 0 << "\n"; 
//     exit(0);
//   }

//   cout << calc(A, B) << "\n";

//   return 0;
// }

/*
	날짜: 2023-08-08
	횟수: 2
    특이사항: 한 번 더 풀어보자.
*/