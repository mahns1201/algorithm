#include <bits/stdc++.h>
using namespace std;

/*
    날짜: 2024-02-12
	횟수: 1
    메모: 꼭 다시 풀어보고 왜 이렇게 되는지 생각하기
*/

const int max_val = 100004;
int n, k, x;
int visited[max_val];
int cnt[max_val];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    if (n==k) {
        cout << "0\n1\n";
        exit(0);
    }
    queue<int> q;
    q.push(n);
    cnt[n] = 1;
    visited[n] = 1;
    while (!q.empty()) {
        x = q.front(); q.pop();
        for (int next: {x-1, x*2, x+1}) {
            if (0<=next && next<=100000) {
                if (!visited[next]) {
                    q.push(next);
                    visited[next] = visited[x]+1;
                    cnt[next] += cnt[x];
                } else if (visited[next] == visited[x]+1) {
                    cnt[next] += cnt[x];
                }
            }
        }
    }

    cout << visited[k]-1 << "\n" << cnt[k] << "\n";

    return 0;
}