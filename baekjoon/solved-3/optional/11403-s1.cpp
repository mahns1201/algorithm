#include <bits/stdc++.h>
using namespace std;

/*
	날짜: 2024-02-22
	횟수: 1
*/

const int MAX_NUM = 104;
int n, t;
vector<int> arr_v[MAX_NUM];
int result[MAX_NUM][MAX_NUM];
int visited[MAX_NUM];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> t;
            if (t) arr_v[i].push_back(j);
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            queue<int> q;
            q.push(i);
            while (!q.empty()) {
                int y = q.front(); q.pop();
                visited[y] = 1;
                for (int ny: arr_v[y]) {
                    if (ny == j) {
                        result[i][j] = 1;
                        break;
                    }
                    if (visited[ny]) continue;
                    q.push(ny);
                }
            }
            memset(visited, 0, sizeof(visited));
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}