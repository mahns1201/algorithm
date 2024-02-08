#include <bits/stdc++.h>
using namespace std;

/*
	날짜: 2024-02-08
	횟수: 1
*/

const int max_val = 1004;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int n, m, y, x;
int mp[max_val][max_val];
int visited[max_val][max_val];
pair<int, int> start;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> mp[i][j];
            if (mp[i][j] == 2) start = {i, j};
        }
    }

    queue<pair<int, int>> q;
    q.push({start.first, start.second});
    visited[start.first][start.second] = 1;
    while(q.size()) {
        tie(y, x) = q.front(); q.pop();
        for (int t=0; t<4; t++) {
            int ny = y + dy[t];
            int nx = x + dx[t];
            if (ny<0 || ny>=n || nx<0 || nx>=m) continue;
            if (visited[ny][nx]) continue;
            if (mp[ny][nx] == 0) continue;

            q.push({ny, nx});
            visited[ny][nx] = visited[y][x] + 1;
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (mp[i][j] == 1 && visited[i][j] == 0) visited[i][j] -=1;
            else if (visited[i][j]) visited[i][j] -=1;
            cout << visited[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}