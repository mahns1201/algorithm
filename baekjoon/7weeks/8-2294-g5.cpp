#include <bits/stdc++.h> 
using namespace std; 

/*
    날짜: 2024-09-19
	횟수: 1
    메모: 다시 풀어보자
*/

const int max_ = 987654321;
const int max_k = 10004;

int n, k, result = max_;
int dp[max_k];
set<int> s;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;

    for(int i=0; i<n; i++) {
        int t;
        cin >> t;
        s.insert(t);
    }

    fill(&dp[0], &dp[0] + max_k, max_);

    dp[0] = 0;
    for(int it: s) {
        for(int i=1; i<=k; i++) {
            if(i-it >= 0) {
                dp[i] = min(dp[i], dp[i-it] + 1);
            } 
        }
    }

    cout << (dp[k] == max_ ? -1 : dp[k]) << "\n";

    return 0;
}
