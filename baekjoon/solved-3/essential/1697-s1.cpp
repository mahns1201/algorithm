#include <bits/stdc++.h>
using namespace std;

/*
	날짜: 2024-02-11
	횟수: 2
    메모: 그래프 탐색 기본에 충실하자: visited, 방문 유효성(!visited[x], 범위 확인)
    메모(2): visited = 1 -> 호출과 호출 -> visited = 1의 차이
*/

int n, m, x, depth;
queue<pair<int, int>> q;
int visited[100004];

bool is_valid(int x) {
    if (x < 0 || 100000 < x || visited[x]) return false;
    else return true;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;

    if (n == m) {
        cout << 0 << "\n";
        exit(0);
    }

    q.push({n, 0});
    visited[n] = 1;
    while(q.size()) {
        tie(x, depth) = q.front(); q.pop();
        // cout << x << " " << depth << "\n";

        if (x-1==m || x*2==m || x+1==m) {
            cout << depth+1 << "\n";
            exit(0);
        }

        if (is_valid(x-1)) {
            visited[x-1] = 1;
            q.push({x-1, depth+1});
        }

        if (is_valid(x*2)) {
            visited[x*2] = 1;
            q.push({x*2, depth+1});
        }

        if (is_valid(x+1)) {
            visited[x+1] = 1;
            q.push({x+1, depth+1});
        }
    }

    return 0;
}

// const int max_val = 100004;
// int n, k, x, y;
// int visited[max_val];
// bool is_valid(int x) {
//     if (x<0 || x>100000 || visited[x]) return false;
//     else return true;
// }
// int main() {
//     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//     cin >> n >> k;

//     queue<pair<int,int>> q;
//     q.push({n, 0});
//     visited[n] = 1;
//     while (!q.empty()) {
//         tie(x, y) = q.front(); q.pop();
//         if (x==k) {
//             cout << y << "\n";
//             break;
//         }
//         if (x+1==k || x*2==k || x-1==k) {
//             cout << y+1 << "\n";
//             break;
//         }
        
//         if (is_valid(x+1)) {
//             visited[x+1] = 1;
//             q.push({x+1, y+1});
//         }
//         if (is_valid(x*2)) {
//             visited[x*2] = 1;
//             q.push({x*2, y+1});
//         }
//         if (is_valid(x-1)) {
//             visited[x-1] = 1;
//             q.push({x-1, y+1});
//         }
//     }

//     return 0;
// }