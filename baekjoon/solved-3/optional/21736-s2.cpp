#include <bits/stdc++.h>
using namespace std;

/*
	날짜: 2024-02-08
	횟수: 1
*/


const int max_val = 604;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int n, m, result;
string input;
char mp[max_val][max_val];
int visited[max_val][max_val];
pair<int, int> start;

void dfs(int y, int x) {
    visited[y][x] = 1;

    for (int t=0; t<4; t++) {
        int ny = y + dy[t];
        int nx = x + dx[t];

        if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
        if (visited[ny][nx]) continue;
        if (mp[ny][nx] == 'X') continue;

        if (mp[ny][nx] == 'P') result++;
        dfs(ny, nx);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    
    for (int i=0; i<n; i++) {
        cin >> input;
        for (int j=0; j<input.size(); j++) {
            mp[i][j] = input[j];
            if (input[j] == 'I') start = {i, j};
        } 
    }

    dfs(start.first, start.second);
    
    if (result) cout << result << "\n";
    else cout << "TT\n";

    return 0;
}