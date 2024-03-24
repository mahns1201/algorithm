#include <bits/stdc++.h>
using namespace std;

/*
	날짜: 2024-03-24
	횟수: 1
*/

const int MAX_N = 1004;
int n, result;
int dp[MAX_N];
// void dfs(int x, int visited_cnt) {
//     if(visited_cnt == 2*n) {
//         result++;
//         return;
//     }

//     if(x != n-1) {
//         dfs(x+2, visited_cnt+4);
//     }

//     dfs(x+1, visited_cnt+2);
// }

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;

    dp[0] = 1;
    dp[1] = 2;

    for(int i=2; i<n; i++) dp[i] = (dp[i-1] + dp[i-2]) % 10007;

    cout << dp[n-1] << '\n';

    return 0;
}