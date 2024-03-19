#include <bits/stdc++.h>
using namespace std;

/*
    날짜: 2024-03-20
	횟수: 1
    메모: 2번 째 비교 시, if((t & (1<<k)) != 0) == 0은 왜 안 되는지 확인
*/

int n, m, ret;
string s;
int mp[4][4];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        cin >> s;
        for(int j=0; j<m; j++) mp[i][j] = s[j] - '0';
    }
    
    // 0 0 1 1 0 1
    // 1 0 1
    // 0 0 0
    for(int t=0; t<(1<<n*m); t++) {
        int sum = 0;
        for(int i=0; i<n; i++) {
            int curr = 0;
            for(int j=0; j<m; j++) {
                int k = i * m + j;
                if((t & (1<<k)) == 0) {
                    curr = curr * 10 + mp[i][j];
                } else {
                    sum += curr;
                    curr = 0;
                }
            }
            sum += curr;
        }

        for(int j=0; j<m; j++) {
            int curr = 0;
            for(int i=0; i<n; i++) {
                // cout << i << ' ' << j << " | ";
                int k = i * m + j;
                if((t & (1<<k)) != 0) {
                    curr = curr * 10 + mp[i][j];
                } else {
                    sum += curr;
                    curr = 0;
                }
            }
            sum += curr;
            // cout << '\n';
        }
        // cout << sum << '\n';
        ret = max(ret, sum);
    }

    cout << ret << '\n';

    return 0;
}