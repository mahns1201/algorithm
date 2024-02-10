#include <bits/stdc++.h>
using namespace std;

/*
	날짜: 2024-02-11
	횟수: 1
    메모: 그래프 탐색 기본에 충실하자: visited, 방문 유효성(!visited[x], 범위 확인)
*/

int n, m, x, depth;
queue<pair<int, int>> q;
int visited[100004];

bool is_valid(int x) {
    if (x < 0 || 100000 < x || visited[x]) return false;
    else return true;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;

    if (n == m) {
        cout << 0 << "\n";
        exit(0);
    }

    q.push({n, 0});
    visited[n] = 1;
    while(q.size()) {
        tie(x, depth) = q.front(); q.pop();
        // cout << x << " " << depth << "\n";

        if (x-1==m || x*2==m || x+1==m) {
            cout << depth+1 << "\n";
            exit(0);
        }

        if (is_valid(x-1)) {
            visited[x-1] = 1;
            q.push({x-1, depth+1});
        }

        if (is_valid(x*2)) {
            visited[x*2] = 1;
            q.push({x*2, depth+1});
        }

        if (is_valid(x+1)) {
            visited[x+1] = 1;
            q.push({x+1, depth+1});
        }
    }

    return 0;
}