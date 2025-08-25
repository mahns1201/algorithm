// https://www.acmicpc.net/problem/1068

#include <bits/stdc++.h>
using namespace std;

/*
    날짜: 2025-08-26
	횟수: 2
    메모: 반드시 루트 노드가 0번 idx 라는 보장은 없다.
*/

int n, del_idx, ret;
int nodes[54];

void del_nodes(int idx) {
    nodes[idx] = -2;
    for (int i=0; i<n; i++) if (nodes[i] == idx) del_nodes(i);
}

bool is_leaf(int idx) {
    if (nodes[idx] == -2) return false;
    for (int i=0; i<n; ++i)
        if (nodes[i] == idx) return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i=0; i<n; ++i) cin >> nodes[i];
    cin >> del_idx;

    del_nodes(del_idx);

    for (int i=0; i<n; ++i)
        if (is_leaf(i)) ++ret;

    cout << ret << "\n";

    return 0;
}

/*
    날짜: 2023-09-06
	횟수: 1
    메모: 다시 한 번 더 풀 것.
*/

// int n, a, b, temp, root;
// vector<int> v[54];

// int dfs(int here) {
//     int ret = 0;
//     int child = 0;

//     for (int there: v[here]) {
//         if (there == b) continue;
//         ret += dfs(there);
//         child++;
//     }

//     if (child == 0) return 1;
//     return ret;
// }

// int main() {
//     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//     cin >> n;
    
//     for (int i=0; i<n; i++) {
//         cin >> temp;
//         if (temp == -1) root = i;
//         else v[temp].push_back(i);
//     }

//     cin >> b;
//     if (b == root) {
//         cout << 0 << "\n";
//         return 0;
//     }

//     cout << dfs(root) << "\n";

//     return 0;
// }
