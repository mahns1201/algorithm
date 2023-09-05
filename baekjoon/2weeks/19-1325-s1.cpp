// https://www.acmicpc.net/problem/17298

/*
    날짜: 2023-09-05
	횟수: 1
    메모: 다시 한 번 더 풀 것.
*/
#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, mx;
int visited[10004];
int dp[10004];
vector<int> ret[10004];

int dfs(int here) {
    visited[here] = 1;
    int v = 1;

    for (int h: ret[here]) {
        if (visited[h]) continue;
        v += dfs(h);
    }
    return v;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    while (m--) {
        cin >> a >> b;
        ret[b].push_back(a);
    }
 
    for (int i=1; i<=n; i++) {
        memset(visited, 0, sizeof(visited));
        dp[i] = dfs(i);
        mx = max(dp[i], mx);
    }

    for (int i=1; i<=n; i++) {
        if (dp[i] == mx) cout << i << " ";
    }
    cout << "\n";

    return 0;
}