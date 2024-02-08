#include <bits/stdc++.h>
using namespace std;

/*
	날짜: 2024-02-08
	횟수: 1
    메모: dp 기본 문제 연습하자
*/

const int max_val = 304;
int n, t;
int stairs[max_val];
int dp[max_val];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i=1; i<n+1; i++) cin >> stairs[i];
    dp[1] = stairs[1];
    dp[2] = stairs[1] + stairs[2];
    dp[3] = max(stairs[1]+stairs[3], stairs[2]+stairs[3]);
    for (int i=4; i<n+1; i++) dp[i] = max(stairs[i-1]+dp[i-3]+stairs[i], dp[i-2]+stairs[i]);
    cout << dp[n];

    return 0;
}