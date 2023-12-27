// https://www.acmicpc.net/problem/4179

#include <bits/stdc++.h>
using namespace std;

/*
    날짜: 2023-12-28
	횟수: 1
    메모: bfs 복습, (y, x) input r, c 매칭
*/

const int max_n = 1004;
const int INF = 987654321;
string s;
int dy[4] = {0, 1, 0, -1};
int dx[4] = {-1, 0, 1, 0};
int r, c, y, x;
int mp[max_n][max_n];
int seo_visited[max_n][max_n];
int fire_visited[max_n][max_n];

// void fire_bfs(int sy, int se) {
//     queue<pair<int, int>> q;
//     fire_visited[sy][se] = 1;
//     q.push({sy, se});

//     while (q.size()) {
//         tie(y, x) = q.front(); q.pop();
//         for (int t=0; t<4; t++) {
//             int ny = y + dy[t];
//             int nx = x + dx[t];

//             if (ny < 0 || c < ny || nx < 0 || r < nx) continue;
//             if (fire_visited[ny][nx] != INF) continue;
//             if (mp[ny][nx] == '#') continue;
//             fire_visited[ny][nx] = fire_visited[y][x] + 1;
//             q.push({ny, nx});
//         }
//     }
// }

void seo_bfs(int i, int j) {
    queue<pair<int, int>> q;
    q.push({i, j});
    seo_visited[i][j] = 1;

    while(q.size()) {
        tie(y, x) = q.front(); q.pop();
        if (y == 0 || y == r-1 || x == 0 || x == c-1) {
            cout << seo_visited[y][x] << "\n";
            exit(0);
        }

        for (int t=0; t<4; t++) {
            int ny = y + dy[t];
            int nx = x + dx[t];

            if (ny < 0 || r <= ny || nx < 0 || c <= nx) continue;
            if (mp[ny][nx] == '#') continue;
            if (seo_visited[ny][nx]) continue;
            if (fire_visited[ny][nx] <= seo_visited[y][x] + 1) continue;

            seo_visited[ny][nx] = seo_visited[y][x] + 1;
            q.push({ny, nx});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> r >> c;
    pair<int, int> start_point;
    vector<pair<int, int>> start_fires;
    queue<pair<int, int>> q;

    fill(&fire_visited[0][0], &fire_visited[0][0] + 1004 * 1004, INF);

    for (int i=0; i<r; i++) {
        cin >> s;
        for (int j=0; j<s.size(); j++) {
            mp[i][j] = s[j];
            if (mp[i][j] == 'J') {
                start_point = {i, j};
            }

            if (mp[i][j] == 'F') {
                // start_fires.push_back({i, j});
                q.push({i, j});
                fire_visited[i][j] = 1;
            }
        }
    }

    // for (auto start_fire: start_fires) {
    //     cout << start_fire.first << " " << start_fire.second << "\n";
    //     fire_bfs(start_fire.first, start_fire.second);
    // }

    
    while (q.size()) {
        tie(y, x) = q.front(); q.pop();
        for (int t=0; t<4; t++) {
            int ny = y + dy[t];
            int nx = x + dx[t];

            if (ny < 0 || r <= ny || nx < 0 || c <= nx) continue;
            if (fire_visited[ny][nx] != INF) continue;
            if (mp[ny][nx] == '#') continue;
            fire_visited[ny][nx] = fire_visited[y][x] + 1;
            q.push({ny, nx});
        }
    }

    seo_bfs(start_point.first, start_point.second);

    cout << "IMPOSSIBLE\n";

    return 0;
}