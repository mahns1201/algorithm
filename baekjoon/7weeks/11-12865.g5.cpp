
#include <bits/stdc++.h>
using namespace std;

/*
    날짜: 2024-09-19
	횟수: 1
*/

int T, k, dp[100004];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    scanf("%d %d", &T, &k);
    
    while(T--) {
        int w, v;
        scanf("%d %d", &w, &v);
        for(int i=k; i>=w; i--) {
            dp[i] = max(dp[i], dp[i-w] + v);
        }
    }

    cout << dp[k] << "\n";

    return 0;
}