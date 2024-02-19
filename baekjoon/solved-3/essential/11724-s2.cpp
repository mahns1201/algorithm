#include <bits/stdc++.h>
using namespace std;

/*
	날짜: 2024-02-20
	횟수: 1
*/

const int N_MAX = 1004;
int n, m, t_left, t_right;
vector<int> v[N_MAX];
int visited[N_MAX];
void dfs(int n) {
    visited[n] = 1;
    for (int i=0; i<v[n].size(); i++) {
        if (visited[v[n][i]]) continue;
        dfs(v[n][i]);
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        cin >> t_left >> t_right;
        v[t_left].push_back(t_right);
        v[t_right].push_back(t_left);
    }

    int result = 0;
    for (int i=1; i<=n; i++) {
        if (visited[i]) continue;
        result ++;
        dfs(i);
    }
    
    cout << result << "\n";

    return 0;
}