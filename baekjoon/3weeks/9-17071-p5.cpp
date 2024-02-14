#include <bits/stdc++.h>
using namespace std;

/*
    날짜: 2024-02-15
	횟수: 1
    메모: 꼭 다시 풀어볼 것.
*/

const int MAX = 500000;
int n, k;
int visited[2][MAX+4];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;

    if (n==k) {
        cout << "0\n";
        return 0;
    }

    queue<int> q;
    int depth = 1;
    visited[0][n] = 1;
    q.push(n);
    bool is_find = false;
    while(!q.empty()) {
        int q_size = q.size();
        k += depth;
        if (MAX < k) break;
        if (visited[depth%2][k]) {
            is_find = true;
            break;
        }
        for (int t=0; t<q_size; t++) {
            int here = q.front(); q.pop();
            
            for (int next: {here-1, here+1, here*2}) {
                if (next<0 || MAX<next) continue;
                if (visited[depth%2][next]) continue;
                visited[depth%2][next] = visited[(depth+1)%2][here] + 1;
                q.push(next);
                if (next == k) {
                    is_find = true;
                    break;
                }
            }
            if (is_find) break;
        }
        if (is_find) break;
        depth ++;
    }

    if (is_find) cout << depth << "\n";
    else cout << "-1\n";

    return 0;
}