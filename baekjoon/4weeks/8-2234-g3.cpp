#include <bits/stdc++.h>
using namespace std;

/*
    날짜: 2024-03-17
	횟수: 1
*/

const int MAX_VAL = 54;
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
int n, m, max_map_cnt, change_max_map_cnt;
int ret_room_cnt, ret_max_map_cnt, ret_change_max_map_cnt;
int mp_wall[MAX_VAL][MAX_VAL];
int mp_wall_origin[MAX_VAL][MAX_VAL];
int visited[MAX_VAL][MAX_VAL];

void dfs(int y, int x) {
    max_map_cnt++;
    change_max_map_cnt++;
    // cout << change_max_map_cnt << '\n';
    ret_max_map_cnt = max(ret_max_map_cnt, max_map_cnt);
    ret_change_max_map_cnt = max(ret_change_max_map_cnt, change_max_map_cnt);
    visited[y][x] = 1;

    for(int t=0; t<4; t++) {
        int ny = y + dy[t];
        int nx = x + dx[t];
        
        if(ny<0 || ny>=n || nx<0 || nx>=m) continue;
        if(visited[ny][nx]) continue;

        // t -> 0 = 북 mp_wall[y][x] & 1<<2 -> 0이면 가능 1이면 벽
        // t -> 1 = 동 mp_wall[y][x] & 1<<3
        // t -> 2 = 남 mp_wall[y][x] & 1<<4
        // t -> 3 = 서 mp_wall[y][x] & 1<<1
        if(t == 0 && mp_wall[y][x] & (1<<1)) continue;
        if(t == 1 && mp_wall[y][x] & (1<<2)) continue;
        if(t == 2 && mp_wall[y][x] & (1<<3)) continue;
        if(t == 3 && mp_wall[y][x] & (1<<0)) continue;

        dfs(ny, nx);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> m >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> mp_wall[i][j];
            mp_wall_origin[i][j] = mp_wall[i][j];
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(!visited[i][j]) {
                max_map_cnt = 0;
                ret_room_cnt++;
                dfs(i, j);
            }
        }
    }

    cout << ret_room_cnt << '\n';
    cout << ret_max_map_cnt << '\n';

    ret_change_max_map_cnt = 0;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            for(int t=0; t<4; t++) {
                // mp_wall 변경 로직
                memset(visited, 0, sizeof(visited));
                mp_wall[i][j] &= ~(1<<t);
                for(int yy=0; yy<n; yy++) {
                    for(int xx=0; xx<m; xx++) {
                        if(!visited[yy][xx]) {
                            // cout << yy << ' ' << xx << '\n';
                            change_max_map_cnt = 0;
                            dfs(yy, xx);
                        }
                    }
                }
                mp_wall[i][j] = mp_wall_origin[i][j];
            }
        }
    }

    
    cout << ret_change_max_map_cnt << '\n';
    
    return 0;
}