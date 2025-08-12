// https://www.acmicpc.net/problem/2583

/*
    날짜: 2025-08-12
	횟수: 2
    특이사항: 좌표 설정을 잘해야 한다.
*/
#include <bits/stdc++.h>
using namespace std;

const int MAX = 104;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int mp[MAX][MAX];
int visited[MAX][MAX];
int ret, result, n, m, k, area;
vector<int> v_result;

void dfs(int y, int x) {
    area++;
    visited[y][x] = 1;

    for (int t=0; t<4; t++) {
        int ny = y + dy[t];
        int nx = x + dx[t];

        if (ny<0 || nx<0 || ny>=n || nx>= m) {
            continue;
        }

        if (!mp[ny][nx] || visited[ny][nx]) {
            continue;
        }

        dfs(ny, nx);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n >> m >> k;

    // fill(&mp[0][0], &mp[MAX][MAX], 1);

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            // cout << mp[i][j] << " ";
            mp[i][j] = 1;
        }
        // cout << "\n";
    }


    while(k--) {
        int lx, ly, rx, ry;
        cin >> lx >> ly >> rx >> ry;

        for (int i=ly; i<ry; i++) {
            for (int j=lx; j<rx; j++) {
                mp[i][j] = 0;
            }
        }

        // cout << "\n\n\n";

        // for (int i=0; i<n; i++) {
        //     for (int j=0; j<m; j++) {
        //         cout << mp[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
    }

    // cout << "\n\n\n";

    // for (int i=0; i<n; i++) {
    //     for (int j=0; j<m; j++) {
    //         cout << mp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    // cout << "\n\n\n";

    // for (int i=0; i<n; i++) {
    //     for (int j=0; j<m; j++) {
    //         cout << visited[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    // cout << "\n\n\n";

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            // cout << i << " " << j << " | " << mp[i][j] << " " << visited[i][j] << "\n";
            if (mp[i][j] && !visited[i][j]) {
                dfs(i, j);
                ret++;
            }
            if (area) {
                v_result.push_back(area);
                area = 0;
            }
        }
        

        
    }

    sort(v_result.begin(), v_result.end());

    cout << ret << "\n";
    for (int it: v_result) {
        cout << it << " ";
    }
    cout << "\n";

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// int N, M, K, cnt;
// int dx[4] = {1, 0, -1, 0};
// int dy[4] = {0, 1, 0, -1};
// bool adj[104][104];
// bool visited[104][104];
// vector<int> ret;

// void dfs(int x, int y) {
//   cnt++;
//   // cout << "x: " << x << " y: " << y << "\n";
//   visited[x][y] = 1;
//   for(int i=0; i<4; i++) {
//     int nx = x + dx[i];
//     int ny = y + dy[i];
//     if (nx < 0 || ny < 0 || N <= nx || M <= ny) continue;
//     if (adj[nx][ny] && !visited[nx][ny]) {
//       dfs(nx, ny);
//     }
//   }
// }

// int main() {
//   ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//   cin >> M >> N >> K;
//   for (int i=0; i<N; i++) {
//     for (int j=0; j<M; j++) {
//       adj[i][j] = true;
//     }
//   }

//   for (int i=0; i<K; i++) {
//     int x1, y1, x2, y2;
//     cin >> x1 >> y1 >> x2 >> y2;

//     for (int j=x1; j<x2; j++) {
//       for (int k=y1; k<y2; k++) {
//         adj[j][k] = false;
//       }
//     }
//   }

//   // for (int i=0; i<N; i++) {
//   //   for (int j=0; j<M; j++) {
//   //     cout << adj[i][j] << " ";
//   //   }
//   //   cout << "\n";
//   // }

//   int total = 0;
//   for (int i=0; i<N; i++) {
//     for (int j=0; j<M; j++) {
//       if (adj[i][j] && !visited[i][j]) {
//         total++;
//         cnt=0;
//         dfs(i, j);
//         // cout << cnt << "\n";
//         ret.push_back(cnt);
//       }
//     }
//   }

//   cout << total << "\n";
//   sort(ret.begin(), ret.end());
//   for (int r: ret) {
//     cout << r << " ";
//   }
//   cout << "\n";
  
//   return 0;
// }