#include <bits/stdc++.h> 
using namespace std; 

/*
    날짜: 2024-09-19
	횟수: 1
    메모: 다시 풀어보자
*/

const int max_ = 10004;

int n, m1, m2, p, c;
int dp[max_];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    while(true) {
        scanf("%d %d.%d", &n, &m1, &m2);
        if(n==0) break;

        memset(dp, 0, sizeof(dp));
        int price = m1 * 100 + m2;
        
        for(int i=0; i<n; i++) {
            scanf("%d %d.%d", &c, &m1, &m2);
            p = m1*100+m2;
            
            for(int j=p; j<=price; j++) {
                dp[j] = max(dp[j], dp[j-p] + c);
            }
        }

        cout << dp[price] << "\n";

    }

    return 0;
}
