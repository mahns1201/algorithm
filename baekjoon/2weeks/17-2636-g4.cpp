// https://www.acmicpc.net/problem/2636

#include <bits/stdc++.h>
using namespace std;

/*
	날짜: 2025-08-25
	횟수: 2
*/

const int MAX = 104;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int mp[MAX][MAX], visited[MAX][MAX];
int n, m, ret1, ret2;
vector<pair<int, int>> v;

int check() {
    int ret = 0;

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) if (mp[i][j] == 1) ret++;
    }

    if (ret) ret2 = ret;

    return ret;
}

void melt() {
    vector<pair<int, int>> vv;
    
    for (auto it: v) {
        if (mp[it.first][it.second]) continue;

        for (int t=0; t<4; t++) {
            int ny = it.first + dy[t];
            int nx = it.second + dx[t];

            if (ny<0 || nx<0 || ny>=n || nx>=m) continue;
            if (mp[ny][nx]) {
                vv.push_back({ ny, nx });
                // break;
            }
        }
    }

    for(auto it: vv) mp[it.first][it.second] = 0;
}

void dfs(int y, int x) {
    v.push_back({ y, x });
    visited[y][x] = 1;

    for (int t=0; t<4; t++) {
        int ny = y + dy[t];
        int nx = x + dx[t];

        if (ny<0 || nx<0 || ny>=n || nx>=m) continue;
        if (mp[ny][nx] == 1 || visited[ny][nx]) continue;

        dfs(ny, nx);
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) cin >> mp[i][j];
    }

    while(check()) {
        memset(visited, 0, sizeof(visited));
        v.clear();
        ret1++;

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (i<=0 || j<=0 || i>=n-1 || j>=m-1) {
                    if (!mp[i][j] && !visited[i][j]) dfs(i, j);
                }
            }
        }

        melt();
    }

    cout << ret1 <<"\n" << ret2 << "\n";

    return 0;
}

/*
    횟수: 1
*/

// int dy[4] = {-1, 0, 1, 0};
// int dx[4] = {0, 1, 0, -1};
// int n, m;
// int mp[104][104];
// int visited[104][104];
// vector<pair<int, int>> v_area;

// void dfs_get_area(int y, int x) {
//     // cout << y << " " << x << "\n";
//     visited[y][x] = 1;
//     v_area.push_back({y, x});

//     for (int t=0; t<4; t++) {
//         int ny = y + dy[t];
//         int nx = x + dx[t];

//         if (ny < 0 || n <= ny || nx < 0 || m <= nx ) continue;
//         if (visited[ny][nx]) continue;
//         if (mp[ny][nx] == 0) dfs_get_area(ny, nx);
//     }
// }

// void dfs(int y, int x) {
//     for (int t=0; t<4; t++) {
//         int ny = y + dy[t];
//         int nx = x + dx[t];

//         if (ny < 0 || n <= ny || nx < 0 || m <= nx ) continue;
//         // cout << ny << ", " << nx << ": " << mp[ny][nx] << "\n"; 
//         if (mp[ny][nx] == 1) mp[ny][nx] = 2;
//     }
// }

// int main() {
//     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//     cin >> n >> m;
//     for (int i=0; i<n; i++) {
//         for (int j=0; j<m; j++) {
//             cin >> mp[i][j];
//         }
//     }

//     int before_left = 0;
//     int left = 0;
//     int cnt = 0;
//     // int t=1;
//     while (true) {
        
//         dfs_get_area(0, 0);
//         for (auto it: v_area) {
//             dfs(it.first, it.second);
//         }

//         // cout << "\n\n";
//         // for (int i=0; i<n; i++) {
//         //     for (int j=0; j<m; j++) {
//         //         cout << mp[i][j] << " ";
//         //     }
//         //     cout << "\n";
//         // }
//         // cout << "\n\n";

//         for (int ii=0; ii<n; ii++) {
//             for (int jj=0; jj<m; jj++) {
//                 if (mp[ii][jj] == 2) {
//                     left++;
//                     mp[ii][jj] = 0;
//                 } 
//             }
//         }

//         // cout << "left: " << left << "\n";

//         if (left == 0) {
//             cout << cnt << "\n";
//             cout << before_left << "\n";
//             break;
//         }

//         // 초기화
//         cnt++;
//         before_left= left;
//         left = 0;
//         // memset(visited, 0, sizeof(visited));
//         memset(visited, 0, sizeof(visited));
//         while(!v_area.size()) v_area.erase(v_area.begin());
//     }



//     return 0;
// }
