#include <bits/stdc++.h>
using namespace std;

/*
	날짜: 2024-02-19
	횟수: 1
    메모: 문제를 제대로 이해하지 못했다. 다시 꼭 풀어보길...
*/

int n, max_val, result;

void comb(int start, vector<int> v) {
    if (v.size()) {
        // int _sum = 0;
        for (auto i: v) {
            cout << i << " ";
            // _sum += i*i;
            // if (_sum > n) return;
        }
        cout << "\n";
        // cout << _sum << "\n";
        // if (_sum == n) result++;
    }

    for (int i=start+1; i<max_val+1; i++) {
        int t=0;
        t += i*2;
        if (t > n) continue;
        v.push_back(i);
        comb(i, v);
        v.pop_back();
    }
}

// void go () {
//     for (int j=1; j<max_val+1; j++) {
//         cout << j*j << " ";
//         // int _sum = j*j;
//         for (int k=j+1; k<max_val+1; k++) {
//             cout << k*k << " ";
//             // _sum += k*k;
//         }
//         cout << "\n";
//         // cout << _sum << "\n";
//         // if (_sum == n) result++;
//     }
// }

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i=1; i<n+1; i++) {
        if (i*i < n) max_val = i;
    }
    // cout << max_val;
    // go();
    vector<int> v;
    comb(0, v);
    cout << result << "\n";

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// int dp[50004], n;
// int main() {
//     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//     cin >> n;
    
//     for (int i=1; i<=n; i++) {
//         dp[i] = dp[i-1] + 1;
//         for (int j=1; j*j<=i; j++) {
//             dp[i] = min(dp[i], dp[i-j*j]+1);
//         }
//     }

//     cout << dp[n] << "\n";

//     return 0;
// }