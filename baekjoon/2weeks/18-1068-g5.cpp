// https://www.acmicpc.net/problem/1068

/*
    날짜: 2023-09-06
	횟수: 1
    메모: 다시 한 번 더 풀 것.
*/

#include <bits/stdc++.h>
using namespace std;

int n, a, b, temp, root;
vector<int> v[54];

int dfs(int here) {
    int ret = 0;
    int child = 0;

    for (int there: v[here]) {
        if (there == b) continue;
        ret += dfs(there);
        child++;
    }

    if (child == 0) return 1;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    
    for (int i=0; i<n; i++) {
        cin >> temp;
        if (temp == -1) root = i;
        else v[temp].push_back(i);
    }

    cin >> b;
    if (b == root) {
        cout << 0 << "\n";
        return 0;
    }

    cout << dfs(root) << "\n";

    return 0;
}