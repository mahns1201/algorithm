#include <bits/stdc++.h>
using namespace std;

/*
    날짜: 2024-04-18
	횟수: 1
*/

const int MAX_MP = 54;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int r, c, t, result;
int air_idx;
int mp[MAX_MP][MAX_MP];
struct T {
    int r, c, val;
};
vector<T> dusts;

void set_dusts() {
    dusts.clear();

    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            if (mp[i][j]) {
                dusts.push_back({i, j, mp[i][j]});
            }
        }
    }
}

void do_dust_cycle() {
    for(T dust: dusts) {
        for(int t=0; t<4; t++) {
            int ny = dust.r + dy[t];
            int nx = dust.c + dx[t];
            if(ny<0  || ny>r-1 || nx<0 || nx>c-1) continue;
            if(mp[ny][nx] == -1) continue;
            mp[ny][nx] += dust.val / 5;
            mp[dust.r][dust.c] -= dust.val / 5;
        }
    }
}

void do_air_cycle() {
    for(int i=air_idx-1; i>0; i--) {
        mp[i][0] = mp[i-1][0];
    }
    for(int i=0; i<c-1; i++) {
        mp[0][i] = mp[0][i+1];
    }
    for(int i=0; i<air_idx; i++) {
        mp[i][c-1] = mp[i+1][c-1];
    }
    for(int i=c-1; i>0; i--) {
        mp[air_idx][i] = mp[air_idx][i-1];
    }
    mp[air_idx][1] = 0;

    for(int i=air_idx+2; i<r-1; i++) {
        mp[i][0] = mp[i+1][0];
    }
    for(int i=0; i<c-1; i++) {
        mp[r-1][i] = mp[r-1][i+1];
    }
    for(int i=r-1; i>air_idx+1; i--) {
        mp[i][c-1] = mp[i-1][c-1];
    }
    for(int i=c-1; i>0; i--) {
        mp[air_idx+1][i] = mp[air_idx+1][i-1];
    }
    mp[air_idx+1][1] = 0;
}

void get_sum_dust() {
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            if (mp[i][j] > 0) {
                result += mp[i][j];
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> r >> c >> t;

    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            cin >> mp[i][j];
            if (mp[i][j] == -1) air_idx = i-1;
        }
    }

    for(int i=0; i<t; i++) {
        set_dusts();
        do_dust_cycle();
        do_air_cycle();
    }

    get_sum_dust();
    cout << result << '\n';
    
    return 0;
}