#include <bits/stdc++.h>
using namespace std;

/*
    날짜: 2024-02-18
	횟수: 1
    메모: 탐색한 곳부터 다음 탐색을 진행하면 상당수의 반복을 줄일 수 있다.
*/

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
const int MAX = 1504;
string input;
char mp[MAX][MAX];
int n, m, y, x;
int visited_bird[MAX][MAX], visited_water[MAX][MAX];
queue<pair<int, int>> bird_q, bird_temp, water_q, water_temp;

void q_clear(queue<pair<int, int>> &q) {
    queue<pair<int, int>> empty_q;
    swap(q, empty_q);
}

bool find_bird() {
    while (!bird_q.empty()) {
        tie(y, x) = bird_q.front(); bird_q.pop();
        // cout << y << " " << x << "\n";
        for (int t=0; t<4; t++) {
            int ny = y + dy[t];
            int nx = x + dx[t];
            if (ny<0||n<=ny||nx<0||m<=nx||visited_bird[ny][nx]) continue;
            visited_bird[ny][nx] = 1;
            if (mp[ny][nx] == 'L') return true;
            else if (mp[ny][nx] == '.') bird_q.push({ny, nx});
            else if (mp[ny][nx] == 'X') bird_temp.push({ny, nx});
        }
    }
    return false;
}

void melt() {
    // cout << "!\n";
    while (!water_q.empty()) {
        tie(y, x) = water_q.front(); water_q.pop();
        // cout << "! " << y << " " << x << "\n";
        for (int t=0; t<4; t++) {
            int ny = y + dy[t];
            int nx = x + dx[t];
            if (ny<0||n<=ny||nx<0||m<=nx||visited_water[ny][nx]) continue;
            if (mp[ny][nx] == 'X') {
                visited_water[ny][nx] = 1;
                mp[ny][nx] = '.';
                water_temp.push({ny, nx});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    int start_i, start_j;
    for (int i=0; i<n; i++) {
        cin >> input;
        for (int j=0; j<m; j++) {
            mp[i][j] = input[j];
            if (input[j] == 'L') {
                start_i = i;
                start_j = j;
            } 
            if (input[j] == '.' || input[j] == 'L') {
                // cout << i << " " << j << "\n";
                water_q.push({i, j});
            } 
        }
    }

    // cout << start_i << " " << start_j << "\n\n";

    int result = 0;
    visited_bird[start_i][start_j] = 1;
    bird_q.push({start_i, start_j});
    while (true) {
        if (find_bird()) break;
        melt();
        bird_q = bird_temp;
        water_q = water_temp;
        q_clear(bird_temp);
        q_clear(water_temp);
        result ++;
    }

    cout << result << "\n";
    
    return 0;
}