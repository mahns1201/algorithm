#include <bits/stdc++.h>
using namespace std;

/*
    날짜: 2024-02-27
	횟수: 1*
    메모: 획기적인 아이디어.
*/

const int MAX_N = 22;
int n;
char mp[MAX_N][MAX_N];
char mp_cp[MAX_N][MAX_N];

void reverse_mp(int raw) {
    for (int i=0; i<n; i++) {
        if (mp[raw][i] == 'T') mp[raw][i] = 'H';
        else mp[raw][i] = 'T';
    }
}
int get_count() {
    int result = 0;
    for (int j=0; j<n; j++) {
        int h_cnt = 0, t_cnt = 0;
        for (int i=0; i<n; i++) {
            if (mp[i][j] == 'H') h_cnt ++;
            else t_cnt ++;
        }
        result += min(h_cnt, t_cnt);
    }
    return result;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    int ret = 0;
    for (int i=0; i<n; i++) {
        string s;
        cin >> s;
        for (int j=0; j<n; j++) {
            mp[i][j] = s[j];
            mp_cp[i][j] = s[j];
            if (s[j] == 'T') ret ++;
        } 
    }

    // int cnt = 0;
    for (int i=1; i<(1<<n); i++) {
        for (int j=0; j<n; j++) {
            // cnt ++;
            if (i&(1<<j)) {
                // cout << 1 << " ";
                reverse_mp(j);
            }
        }
        // get_count() 호출
        // min()으로 ret 갱신
        ret = min(ret, get_count());
        // mp 원복
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                mp[i][j] = mp_cp[i][j];
            }
        }
        // cout << "\n";
    }

    cout << ret << "\n";

    return 0;
}