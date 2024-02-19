#include <bits/stdc++.h>
using namespace std;

/*
	날짜: 2024-02-20
	횟수: 1
*/

const int N_MAX = 1004;
int n, m, s, t_left, t_right;
vector<int> v[N_MAX];
int visited[N_MAX];

void bfs(int y) {
    visited[y] = 1;
    cout << y << " ";
    for (int i=0; i<v[y].size(); i++) {
        if (visited[v[y][i]]) continue;
        bfs(v[y][i]);
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> s;
    for (int i=0; i<m; i++) {
        cin >> t_left >> t_right;
        v[t_left].push_back(t_right);
        v[t_right].push_back(t_left);
    }
    for (int i=1; i<=n; i++) {
        sort(v[i].begin(), v[i].end());
    }

    bfs(s);

    cout << "\n";
    memset(visited, 0, sizeof(visited));

    queue<int> q;
    visited[s] = 1;
    q.push(s);
    while (!q.empty()) {
        int y = q.front(); q.pop();
        cout << y << " ";
        for (int i=0; i<v[y].size(); i++) {
            if (visited[v[y][i]]) continue;
            visited[v[y][i]] = 1;
            q.push(v[y][i]);
        }
    }
    cout << "\n";

    return 0;
}