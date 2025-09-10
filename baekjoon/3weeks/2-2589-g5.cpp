// https://www.acmicpc.net/problem/2589

#include <bits/stdc++.h>
using namespace std;

/*
    날짜: 2025-09-10
	횟수: 2
    메모: 불필요한 조합 사용 X, 코드를 더 간결하게 작성할 수 있도록.
*/

string s;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int n, m, y, x, result;
int mp[54][54], visited[54][54];
vector<pair<int, int>> v;

void bfs(int ty, int tx) {
    queue<pair<int, int>> q;
    q.push({ ty, tx });
    visited[ty][tx] = 1;

    while(q.size()) {
        tie(y, x) = q.front(); q.pop();

        for (int t=0; t<4; t++) {
            int ny = y + dy[t];
            int nx = x + dx[t];

            if (ny<0 || nx<0 || ny>=n || nx>=m) continue;
            if (!mp[ny][nx] || visited[ny][nx]) continue;

            q.push({ ny, nx });
            visited[ny][nx] = visited[y][x] + 1;
            result = max(result, visited[y][x]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i=0; i<n; i++) {
        cin >> s;
        for (int j=0; j<m; j++) {
            if (s[j] == 'L') {
                mp[i][j] = 1;
                v.push_back({ i, j });
            }
            else mp[i][j] = 0;
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (mp[i][j] == 1) {
                memset(visited, 0, sizeof(visited));
                bfs(i, j);
            } 
        }
    }


    cout << result << "\n";

    return 0;
}

/*
    날짜: 2023-12-18
	횟수: 1
    메모: memset으로 배열 초기화, bfs 공부 다시
*/

const int max_n = 54;
int ret = -987654321;
int N, M, y, x;
char mp[max_n][max_n];
int visited[max_n][max_n];
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { -1, 0, 1, 0 };

void clean_visited() {
    for (int i = 0; i < max_n; i++) {
        for (int j = 0; j < max_n; j++) {
            visited[i][j] = 0;
        }   
    }
}

void bfs(int i, int j) {
    clean_visited();
    // memset(visited, 0, sizeof(visited));
    queue<pair<int, int>> q;
    q.push({i, j});
    visited[i][j] = 1;

    while(q.size()) {
        tie(y, x) = q.front(); q.pop();
        for (int t=0; t<4; t++) {
            int ny = y + dy[t];
            int nx = x + dx[t];

            if (ny < 0 || N <= ny || nx < 0 || M <= nx) continue;
            if (mp[ny][nx] == 'W' || visited[ny][nx]) continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
            ret = max(ret, visited[ny][nx]); 
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> mp[i][j];
        }
    }

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (mp[i][j] == 'L') bfs(i, j);
        }
    }
    
    cout << ret-1 << "\n";
    

    return 0;
}