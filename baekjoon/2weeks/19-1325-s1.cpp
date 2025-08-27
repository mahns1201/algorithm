// https://www.acmicpc.net/problem/1325

#include <bits/stdc++.h>
using namespace std;

/*
    날짜: 2025-08-27
	횟수: 2
*/

int n, m, t1, t2, result, ret;
vector<int> arr[10004];
int visited[10004];
vector<int> v;

void dfs(int here) {
    // cout << "here: " << here << " ";
    ret++;
    visited[here] = 1;

    if (!arr[here].size()) return;

    for (int there: arr[here]) {
        if (visited[there]) continue;
        dfs(there);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    
    for (int i=0; i<m; ++i) {
        cin >> t1 >> t2;
        arr[t2].push_back(t1);
    }

    for (int i=1; i<n+1; i++) {
        ret = 0;
        memset(visited, 0, sizeof(visited));

        dfs(i);
        // cout << "! " << i << "\n\n";

        if (ret == result) {
            v.push_back(i);
        }

        if (ret > result) {
            result = ret;
            v.clear();
            v.push_back(i);
        }
    }

    sort(v.begin(), v.end());

    for (int it: v) cout << it << " ";
    cout << "\n";

    return 0;
}

/*
    날짜: 2023-09-05
	횟수: 1
    메모: 다시 한 번 더 풀 것.
*/

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