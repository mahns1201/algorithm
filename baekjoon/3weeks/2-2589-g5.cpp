// https://www.acmicpc.net/problem/2589

/*
    날짜: 2023-12-18
	횟수: 1
    메모: memset으로 배열 초기화, bfs 공부 다시
*/
#include <bits/stdc++.h>
using namespace std;

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