#include <bits/stdc++.h> 
using namespace std; 

/*
    날짜: 2024-09-19
	횟수: 2
    메모
        - 비트마스킹 & 완전 탐색
        - DP n번, 1번만 사용 -> 오른쪽에서 dp 채우기
*/

int n, t, dp[104];
vector<int> hp;
vector<int> joy;

// dp
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> t;
        hp.push_back(t);
    }
    for(int i=0; i<n; i++) {
        cin >> t;
        joy.push_back(t);
    }

    for(int i=0; i<n; i++) {
        for(int j=100; j>hp[i]; j--) {
            dp[j] = max(dp[j], dp[j-hp[i]] + joy[i]);
        }
    }

    cout << dp[100] << "\n";

    return 0;
}

// 비트마스킹 & 완전 탐색
// int n, t, result;
// vector<int> hp;
// vector<int> joy;

// int main() {
//     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//     cin >> n;
//     for(int i=0; i<n; i++) {
//         cin >> t;
//         hp.push_back(t);
//     }
//     for(int i=0; i<n; i++) {
//         cin >> t;
//         joy.push_back(t);
//     }

//     for(int i=0; i<(1<<n); i++) {
//         int die_condition = 100;
//         int ret = 0;
//         for(int j=0; j<n; j++) {
//             if(i&(1<<j)) {
//                 die_condition -= hp[j];
//                 ret += joy[j];
//             }
//         }
//         if(die_condition > 0) result = max(result, ret);
        
//     }
    

//     cout << result << "\n";

//     return 0;
// }
