#include <bits/stdc++.h>
using namespace std;

/*
	날짜: 2024-03-31
	횟수: 1
*/

const int MAX_N = 101;
int n, m, a, b, temp, result;
vector<int> arr[MAX_N];
int visited[MAX_N];

void bfs(int from, int to) {
    visited[from] = 1;
    queue<int> q;
    q.push(from);

    while(!q.empty()) {
        int here = q.front(); q.pop();
        
        for(int go: arr[here]) {
            if(visited[go]) continue;
            if(go == to) {
                temp = visited[here];
                return;
            }
            visited[go] = visited[here] + 1;
            q.push(go);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    int sum_temp = 987654321;
    for(int i=1; i<n+1; i++) {
        int sum = 0;
        for(int j=1; j<n+1; j++) {
            memset(visited, 0, sizeof(visited));
            if(i==j) continue;
            temp = 987654321;
            bfs(i, j);
            sum += temp;
        }

        if(sum_temp>sum) {
            sum_temp = sum;
            result = i;
        }
    }

    cout << result << '\n';

    return 0;
}