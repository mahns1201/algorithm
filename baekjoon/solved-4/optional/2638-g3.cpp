#include <bits/stdc++.h>
using namespace std;

/*
	날짜: 2024-04-02
	횟수: 1
*/

const int MAX_N = 104;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int n, m, checker, ret;
int mp[MAX_N][MAX_N];
int out_mp[MAX_N][MAX_N];
int visited[MAX_N][MAX_N];
vector<pair<int, int>> melt_vector;

bool is_melt() {
    int melt_cnt = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(mp[i][j]==0) melt_cnt++;
        }
    }

    return melt_cnt==n*m ? true : false;
}

void get_melt_list(int y, int x) {
    int surface_cnt = 0;
    for(int t=0; t<4; t++) {
        int ny = y + dy[t];
        int nx = x + dx[t];
        if(ny<0 || n<=ny || nx<0 || m<=nx) continue;
        if(mp[ny][nx]==1) continue;
        if(out_mp[ny][nx]==0) continue;
        surface_cnt++;
    }
    if(surface_cnt>=2) melt_vector.push_back({y, x});
}

void melt() {
    for(auto it: melt_vector) mp[it.first][it.second] = 0;
    ret++;
}

void dfs(int y, int x) {
    if(checker==1) return;
    visited[y][x] = 1;

    for(int t=0; t<4; t++) {
        int ny = y + dy[t];
        int nx = x + dx[t];
        if(ny<0 || n<=ny || nx<0 || m<=nx) {
            checker = 1;
            return;
        }
        if(mp[ny][nx]) continue;
        if(visited[ny][nx]) continue;

        dfs(ny, nx);
    }
}

void make_out_mp() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(out_mp[i][j]) continue;
            memset(visited, 0, sizeof(visited));
            checker = 0;
            dfs(i, j);
            if(checker) out_mp[i][j] = 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> mp[i][j];
        }
    }

    while(true) {
        make_out_mp();
        if(is_melt()) break;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(mp[i][j]==1) get_melt_list(i, j);
            }
        }
        melt();
    }

    cout << ret << '\n';

    return 0;
}