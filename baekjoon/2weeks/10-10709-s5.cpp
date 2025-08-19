// https://www.acmicpc.net/problem/10709

#include <bits/stdc++.h>
using namespace std;

/*
    날짜: 2025-08-18
	횟수: 2
    메모: 횟수 1의 mp 초기화를 적용하면 더 좋을 듯.
*/
const int MAX = 104;
int n, m;
int ret[MAX][MAX];
char mp[MAX][MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) cin >> mp[i][j];
    }

    for (int i=0; i<n; i++) {
        int prev = -1;
        for (int j=0; j<m; j++) {
            // case: 해당 값이 구름인 경우 -> 0
            if (mp[i][j] == 'c') {
                ret[i][j] = 0;
                prev = 0;
                continue;
            }

            if (prev == -1) {
                ret[i][j] = -1;
                continue;
            }

            ret[i][j] = prev + 1;
            prev++;
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) cout << ret[i][j] << " ";
        cout << "\n";
    }

    return 0;
}

/*
	횟수: 1
*/
int y, x;
int maxV = 104;
int ret[104][104];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> y >> x;
    string ts;
    for (int i=0; i<y; i++){
        cin >> ts;
        for (int j=0; j<x; j++) {
            if (ts[j] == 'c') ret[i][j] = 0;
            if (ts[j] == '.') ret[i][j] = -1;
        }
    }

    for (int i=0; i<y; i++) {
        for (int j=0; j<x; j++) {
            if (j == 0) continue;
            if (ret[i][j] == 0) continue;
            if (ret[i][j] == -1 && ret[i][j-1] != -1) ret[i][j] = ret[i][j-1] + 1;
        }
    }

    for (int i=0; i<y; i++) {
        for (int j=0; j<x; j++) {
            cout << ret[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}