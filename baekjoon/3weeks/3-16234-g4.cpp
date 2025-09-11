// https://www.acmicpc.net/problem/16234

#include <bits/stdc++.h>
using namespace std;

/*
    날짜: 2025-09-11
	횟수: 2
*/

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int n, l, r, _sum, _n, _cnt, result;
int mp[54][54], visited[54][54];
vector<pair<int, int>> v;

void dfs(int y, int x) {
    _sum += mp[y][x];
    _n++;
    v.push_back({ y, x });
    visited[y][x] = 1;

    for (int t=0; t<4; t++) {
        int ny = y + dy[t];
        int nx = x + dx[t];

        if (ny<0 || nx<0 || ny>=n || nx>=n) continue;
        if (abs(mp[ny][nx] - mp[y][x]) < l || abs(mp[ny][nx] - mp[y][x]) > r || visited[ny][nx]) continue;

        dfs(ny, nx);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> l >> r;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) cin >> mp[i][j];
    }

    while(_cnt < n*n) {
        _cnt = 0;
        memset(visited, 0, sizeof(visited));
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                _sum = 0;
                _n = 0;
                v.clear();
                if (!visited[i][j]) {
                    _cnt++;
                    dfs(i, j);
                    for (pair<int, int> it: v) mp[it.first][it.second] = _sum / _n;
                }
            }
        }

        if (_cnt != n*n) result++;
    }

    cout << result << "\n";

    return 0;
}

/*
    날짜: 2023-12-19
	횟수: 1
    메모: fill로 초기화, vector 초기화, *bfs에 추가 로직 구현
*/

const int max_n = 54;
int ret = 0;
int N, L, R, sum;
int dy[4] = {0, 1, 0, -1};
int dx[4] = {-1, 0, 1, 0};
int mp[max_n][max_n];
int visited[max_n][max_n];
vector<pair<int, int>> v;
void dfs(int y, int x, vector<pair<int, int>> &v) {
    if (visited[y][x]) return;
    visited[y][x] = 1;

    for (int t=0; t<4; t++) {
        int ny = y + dy[t];
        int nx = x + dx[t];

        if (ny < 0 || N <= ny || nx < 0 || N <= nx) continue;
        if (visited[ny][nx]) continue;
        int temp = abs(mp[y][x] - mp[ny][nx]);
        // cout << "L: " << L << " " << "temp: " << temp << " " << "R: " << R << "\n";
        if (L <= temp && temp <= R) {
            // cout << "! " << ny << " " << nx << "\n";
            sum += mp[ny][nx];
            v.push_back({ny, nx});
            dfs(ny, nx, v);
        }
    }


}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> L >> R;

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> mp[i][j];
        }   
    }

    while(true) {
        // cout << "!" << "\n";
        memset(visited, 0, sizeof(visited));
        bool flag = false;
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                v.clear();
                if (visited[i][j]) continue;
                sum = mp[i][j];
                v.push_back({i, j});
                
                dfs(i, j, v);
                
                if (v.size() == 1) continue;
                // cout << v.size() << "\n";
                for (int t=0; t<v.size(); t++) {
                    mp[v[t].first][v[t].second] = sum / v.size();
                    // cout << "ret: " << ret << "\n";
                    // ret++;
                    flag = true;
                }
            }   
        }  
        // cout << flag << " ";
        if (!flag) break;
        ret++;
    }

    cout << ret << "\n";

    return 0;
}