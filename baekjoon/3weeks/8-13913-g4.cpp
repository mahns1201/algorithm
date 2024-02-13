#include <bits/stdc++.h>
using namespace std;

/*
    날짜: 2024-02-13
	횟수: 1
    메모: trace 배열로 추적하기. 혹은 vector로 구현해보기
*/

const int max_val = 100004;
int n, k, here;
int visited[max_val];
int trace[max_val];
vector<int> v;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    if (n==k) {
        cout << "0\n";
        cout << n << "\n";
        return 0;
    }
    queue<int> q;
    q.push(n);
    visited[n] = 1;
    while(!q.empty()) {
        here = q.front(); q.pop();
        for (int next: {here-1, here*2, here+1}) {
            if (0<=next && next<=100000) {
                if (!visited[next]) {
                    q.push(next);
                    visited[next] = visited[here] + 1;
                    trace[next] = here;
                }
            }
        }
    }

    cout << visited[k] - 1 << "\n";
    for (int i=k; i!=n; i=trace[i]) v.push_back(i);
    v.push_back(n);
    reverse(v.begin(), v.end());
    for (auto i: v) cout << i << " ";
    cout << "\n";

    return 0;
}