// https://www.acmicpc.net/problem/14502

#include <bits/stdc++.h>
using namespace std;

int n, m, ny, nx, ret;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int mp[8][8];
int mp_origin[8][8];
int visited[8][8];

void dfs(int y, int x) {
    visited[y][x] = 1;
    mp[y][x] = 3;

    for (int i=0; i<4; i++) {
        ny = y + dy[i];
        nx = x + dx[i];
        if (ny < 0 || n-1 < ny || nx < 0 || m-1 < nx) continue;
        if (mp[ny][nx] && mp[ny][nx] != 3) continue;
        if (visited[ny][nx]) continue;

        dfs(ny, nx);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0), cout.tie(0);
    cin >> n >> m;

    vector<pair<int, int>> wall_list;
    vector<pair<int, int>> virus_list;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> mp[i][j];
            if(mp[i][j] == 0) wall_list.push_back({ i, j });
            if(mp[i][j] == 2) virus_list.push_back({ i, j });
        }
    }

    memcpy(mp_origin, mp, sizeof(mp));

    // 완전탐색으로 풀겠다.
    for (int i=0; i<wall_list.size(); i++) {
        for (int j=i+1; j<wall_list.size(); j++) {
            for (int k=j+1; k<wall_list.size(); k++) {
                mp[wall_list[i].first][wall_list[i].second] = 1;
                mp[wall_list[j].first][wall_list[j].second] = 1;
                mp[wall_list[k].first][wall_list[k].second] = 1;
                
                for (auto vi: virus_list) {
                    dfs(vi.first, vi.second);
                }
                
                int cnt=0;
                for (int iii=0; iii<n; iii++) {
                    for (int jjj=0; jjj<m; jjj++) {
                        if (mp[iii][jjj] == 0) cnt++;
                    }
                }
                ret = max(ret, cnt);

                memcpy(mp, mp_origin, sizeof(mp_origin));
                fill(&visited[0][0], &visited[0][0] + 8*8, 0);
            }
        }
    }

    cout << ret << "\n";

    return 0;
}