#include <bits/stdc++.h>
using namespace std;

/*
    날짜: 2024-02-16
	횟수: 2
    메모: 2차원 배열을 *, %를 사용하여 1차원으로 넣는 방법이 있다. 2가지 방법으로 다시 풀어보자.
*/

const int MAX = 300;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int n, m, yj, xj, yb, xb;
string input;
char mp[MAX+4][MAX+4];
int visited[MAX+4][MAX+4];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> yj >> xj >> yb >> xb;
    yj--; xj--; yb--; xb--;
    for (int i=0; i<n; i++) {
        cin >> input;
        for (int j=0; j<m; j++) mp[i][j] = input[j];
    }

    queue<int> q;
    visited[yj][xj] = 1;
    q.push(yj*1000+xj);
    int cnt = 0;
    while (true) {
        cnt++;
        queue<int> qq;
        while (!q.empty()) {
            int y = q.front() / 1000;
            int x = q.front() % 1000;
            q.pop();
            for (int t=0; t<4; t++) {
                int ny = y + dy[t];
                int nx = x + dx[t];
                if (ny<0 || n<=ny || nx<0 || m<=nx) continue;
                if (visited[ny][nx]) continue;
                visited[ny][nx] = cnt;
                if (mp[ny][nx] == '#') {
                    cout << cnt << "\n";
                    exit(0);
                } else if (mp[ny][nx] == '1') {
                    mp[ny][nx] = '0';
                    qq.push(ny*1000+nx);
                } else if (mp[ny][nx] == '0') {
                    q.push(ny*1000+nx);
                }
            }
        }
        q = qq;
    }
    
    return 0;
}

// const int MAX = 300;
// int dy[4] = {-1, 0, 1, 0};
// int dx[4] = {0, 1, 0, -1};
// int n, m, yj, xj, yb, xb;
// string input;
// char mp[MAX+4][MAX+4];
// int visited[MAX+4][MAX+4];

// int main() {
//     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//     cin >> n >> m >> yj >> xj >> yb >> xb;
//     yj--; xj--; yb--; xb--;
//     for (int i=0; i<n; i++) {
//         cin >> input;
//         for (int j=0; j<m; j++) mp[i][j] = input[j];
//     }

//     queue<pair<int, int>> q;
//     visited[yj][xj] = 1;
//     q.push({yj, xj});
//     int cnt = 0;
//     while (true) {
//         cnt++;
//         queue<pair<int, int>> qq;
//         while (!q.empty()) {
//             int y=0, x=0;
//             tie(y, x) = q.front(); q.pop();
//             for (int t=0; t<4; t++) {
//                 int ny = y + dy[t];
//                 int nx = x + dx[t];
//                 if (ny<0 || n<=ny || nx<0 || m<=nx) continue;
//                 if (visited[ny][nx]) continue;
//                 visited[ny][nx] = cnt;
//                 if (mp[ny][nx] == '#') {
//                     cout << cnt << "\n";
//                     exit(0);
//                 } else if (mp[ny][nx] == '1') {
//                     mp[ny][nx] = '0';
//                     qq.push({ny, nx});
//                 } else if (mp[ny][nx] == '0') {
//                     q.push({ny, nx});
//                 }
//             }
//         }
//         q = qq;
//     }
    
//     return 0;
// }