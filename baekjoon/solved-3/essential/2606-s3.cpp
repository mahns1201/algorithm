#include <bits/stdc++.h>
using namespace std;

int n, m, t1, t2, result;
vector<int> arr[104];
int visited[104];

void go(int curr) {
    if (visited[curr]) return;
    visited[curr] = 1;
    for (auto i: arr[curr]) go(i);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;

    for (int i=0; i<m; i++) {
        cin >> t1 >> t2;
        arr[t1].push_back(t2);
        arr[t2].push_back(t1);
    }

    go(1);
    
    for (auto i: visited) if (visited[i]) result++;
    cout << result-1 << "\n";

    return 0;
}