#include <bits/stdc++.h>
using namespace std;

string s;
const int max_val = 104;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int n, y, x, result, result_b;
int mp[max_val][max_val], mp_b[max_val][max_val];
int visited[max_val][max_val], visited_b[max_val][max_val];

void dfs(int y, int x, char c) {
    visited[y][x] = 1;

    for (int t=0; t<4; t++) {
        int ny = y + dy[t];
        int nx = x + dx[t];

        if (ny<0 || ny>=n || nx<0 || nx>=n) continue;
        if (visited[ny][nx]) continue;
        if (mp[ny][nx] != c) continue;

        dfs(ny, nx, c);
    }
}
void dfs_b(int y, int x, char c) {
    visited_b[y][x] = 1;

    for (int t=0; t<4; t++) {
        int ny = y + dy[t];
        int nx = x + dx[t];

        if (ny<0 || ny>=n || nx<0 || nx>=n) continue;
        if (visited_b[ny][nx]) continue;
        if (mp_b[ny][nx] != c) continue;

        dfs_b(ny, nx, c);
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> s;
        for (int j=0; j<s.size(); j++) {
            mp[i][j] = s[j];
            mp_b[i][j] = s[j] == 'B' ? 'B' : 'G'; 
        } 
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (!visited[i][j]) result++;
            dfs(i, j, mp[i][j]);
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (!visited_b[i][j]) result_b++;
            dfs_b(i, j, mp_b[i][j]);
        }
    }

    cout << result << " " << result_b << "\n";

    return 0;
}