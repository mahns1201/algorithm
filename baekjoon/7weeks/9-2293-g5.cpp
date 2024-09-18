#include <bits/stdc++.h> 
using namespace std; 

/*
    날짜: 2024-09-19
	횟수: 1
    메모: 잘했지만 다시 한 번.
*/

const int max_ = 10001;
int n, k, t, dp[max_];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    scanf("%d %d", &n, &k);

    dp[0] = 1;
    for(int i=0; i<n; i++) {
        scanf("%d", &t);
        for(int j=t; j<=k; j++) {
            dp[j] += dp[j-t];
        }
    }

    cout << dp[k] << "\n";

    return 0;
}
