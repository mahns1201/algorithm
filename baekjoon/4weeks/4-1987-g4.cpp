#include <bits/stdc++.h>
using namespace std;

/*
    날짜: 2024-03-04
	횟수: 1
    메모: 비트연산자를 이렇게도 쓸 수 있구나...
*/

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
int n, m, ret = 1;
int mp[20][20];
string s;
void go(int y, int x, int c, int cnt) {
    ret = max(ret, cnt);
    for(int t=0; t<4; t++) {
        int ny = y + dy[t];
        int nx = x + dx[t];
        if(ny<0||ny>=n||nx<0||nx>=m) continue;
        if(c & (1 << mp[ny][nx])) continue;
        go(ny, nx, c|(1 << mp[ny][nx]), cnt+1);
    }
    return;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        cin >> s;
        for(int j=0; j<s.size(); j++) mp[i][j] = s[j] - 'A';
    }

    int cnt = 1;
    go(0, 0, (1 << mp[0][0]), cnt);
    cout << ret << '\n';
    return 0;
}