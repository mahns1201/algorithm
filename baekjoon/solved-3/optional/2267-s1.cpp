#include <bits/stdc++.h>
using namespace std;

/*
	날짜: 2024-03-29
	횟수: 1
*/

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int n, cnt_a, cnt_b;
string s;
int mp[26][26];
int visited[26][26];
vector<int> v;

void dfs(int y, int x) {
    visited[y][x] = 1;
    cnt_b++;

    for(int t=0; t<4; t++) {
        int ny = y + dy[t];
        int nx = x + dx[t];

        if(ny<0 || ny>=n || nx<0 || nx >=n) continue;
        if(!mp[ny][nx]) continue;
        if(visited[ny][nx]) continue;

        dfs(ny, nx);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> s;
        for(int j=0; j<s.size(); j++) mp[i][j] = s[j]-'0';
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cnt_b = 0;
            bool temp = false;
            if(visited[i][j] == 0 && mp[i][j]) {
                temp = true;
                cnt_a++;
                dfs(i, j);
            }
            if(temp) v.push_back(cnt_b);
        }
    }

    sort(v.begin(), v.end());
    cout << cnt_a << '\n';
    for(auto it: v) cout << it << '\n';

    return 0;
}