#include <bits/stdc++.h>
using namespace std;

/*
	날짜: 2024-02-11
	횟수: 1
*/

const int max_val = 1004;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int n, m, y, x, result;
int mp[max_val][max_val];
int visited[max_val][max_val];
vector<pair<int, int>> starts;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> m >> n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> mp[i][j];
            if (mp[i][j] == 1) starts.push_back({i, j});
            if (mp[i][j] == -1) visited[i][j] = -1;
        }
    }

    queue<pair<int, int>> q;
    for (pair<int, int> start: starts) {
        q.push(start);
        visited[start.first][start.second] = 1;
    }
    while (q.size()) {
        tie(y, x) = q.front(); q.pop();

        for (int t=0; t<4; t++) {
            int ny = y + dy[t];
            int nx = x + dx[t];

            if (ny<0 || ny>=n || nx<0 || nx>=m) continue;
            if (mp[ny][nx] == -1) continue;
            if (visited[ny][nx]) continue;
            // if (visited[ny][nx] < visited[y][x]) continue;

            visited[ny][nx] = visited[y][x] +1;
            q.push({ny, nx});
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (visited[i][j] == 0) {
                cout << -1 << "\n";
                exit(0);
            }
            result = max(result, visited[i][j]);
        }
    }
    cout << result-1 << "\n";
    return 0;
}