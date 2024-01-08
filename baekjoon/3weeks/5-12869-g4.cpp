// https://www.acmicpc.net/problem/12869

#include <bits/stdc++.h>
using namespace std;

/*
	날짜: 2024-01-09
	횟수: 1
    특이사항: 큰 순서대로 -9, -3, -1은 왜 틀렸는지 확인하고 지도가 아닌 상황에서의 탐색 알고리즘 적용법 연습하기
*/

const int max_n = 64;
int n, x, y, z, xx, yy, zz;
int visited[max_n][max_n][max_n];
int cases[6][3] = {
    {9, 3, 1},
    {9, 1, 3},
    {3, 9, 1},
    {3, 1, 9},
    {1, 9, 3},
    {1, 3, 9}
};
struct T {
    int a, b, c;
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;

    for (int i=0; i<n; i++) {
        if (i == 0) {
            cin >> x;
        } else if (i == 1) {
            cin >> y;
        } else if (i == 2) {
            cin >> z;
        }
    }

    visited[x][y][z] = 1;
    queue<T> q;
    q.push({x, y, z});

    while(q.size()) {
        xx = q.front().a;
        yy = q.front().b;
        zz = q.front().c;
        q.pop();

        for (int i=0; i<6; i++) {
            int nx = max(0, xx - cases[i][0]);
            int ny = max(0, yy - cases[i][1]);
            int nz = max(0, zz - cases[i][2]);

            if (visited[nx][ny][nz]) continue;

            if (nx == 0 && ny == 0 && nz == 0) {
                cout << visited[xx][yy][zz] << "\n";
                exit(0);
            }

            visited[nx][ny][nz] = visited[xx][yy][zz] + 1;
            q.push({nx, ny, nz});
        }
    }

    return 0;
}