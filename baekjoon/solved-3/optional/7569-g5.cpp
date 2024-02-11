#include <bits/stdc++.h>
using namespace std;

/*
	날짜: 2024-02-11
	횟수: 1
    메모: 3차원 일 때 for문 돌릴 때 h -> n -> m 순으로 돌리자
*/

const int max_val = 104;
int dy[6] = {-1, 0, 1, 0, 0, 0};
int dx[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
int n, m, h, y, x, z, result;
int mp[max_val][max_val][max_val];
int visited[max_val][max_val][max_val];
struct T {
    int a, b, c;
};
vector<T> starts;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> m >> n >> h;
    for (int k=0; k<h; k++) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                cin >> mp[i][j][k];
                if (mp[i][j][k] == 1) starts.push_back({i, j, k});
                if (mp[i][j][k] == -1) visited[i][j][k] = -1;
            }
        }
    }

    queue<T> q;
    for (T start: starts) {
        // cout << start.a << " " << start.b << " " << start.c << "\n";
        q.push(start);
        visited[start.a][start.b][start.c] = 1;
    }
    while (q.size()) {
        T t = q.front(); q.pop();
        y = t.a;
        x = t.b;
        z = t.c;

        for (int t=0; t<6; t++) {
            int ny = y + dy[t];
            int nx = x + dx[t];
            int nz = z + dz[t];

            if (ny<0 || ny>=n || nx<0 || nx>=m || nz<0 || nz>=h) continue;
            if (mp[ny][nx][nz] == -1) continue;
            if (visited[ny][nx][nz]) continue;
            // if (visited[ny][nx] < visited[y][x]) continue;

            visited[ny][nx][nz] = visited[y][x][z] +1;
            q.push({ny, nx, nz});
        }
    }

    for (int k=0; k<h; k++) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (visited[i][j][k] == 0) {
                    cout << -1 << "\n";
                    exit(0);
                }
                result = max(result, visited[i][j][k]);
            }
        }
    }
    cout << result-1 << "\n";
    return 0;
}