https://www.acmicpc.net/problem/2583

#include <bits/stdc++.h>
using namespace std;

int N, M, K, cnt;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool adj[104][104];
bool visited[104][104];
vector<int> ret;

void dfs(int x, int y) {
  cnt++;
  // cout << "x: " << x << " y: " << y << "\n";
  visited[x][y] = 1;
  for(int i=0; i<4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (nx < 0 || ny < 0 || N <= nx || M <= ny) continue;
    if (adj[nx][ny] && !visited[nx][ny]) {
      dfs(nx, ny);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> M >> N >> K;
  for (int i=0; i<N; i++) {
    for (int j=0; j<M; j++) {
      adj[i][j] = true;
    }
  }

  for (int i=0; i<K; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    for (int j=x1; j<x2; j++) {
      for (int k=y1; k<y2; k++) {
        adj[j][k] = false;
      }
    }
  }

  // for (int i=0; i<N; i++) {
  //   for (int j=0; j<M; j++) {
  //     cout << adj[i][j] << " ";
  //   }
  //   cout << "\n";
  // }

  int total = 0;
  for (int i=0; i<N; i++) {
    for (int j=0; j<M; j++) {
      if (adj[i][j] && !visited[i][j]) {
        total++;
        cnt=0;
        dfs(i, j);
        // cout << cnt << "\n";
        ret.push_back(cnt);
      }
    }
  }

  cout << total << "\n";
  sort(ret.begin(), ret.end());
  for (int r: ret) {
    cout << r << " ";
  }
  cout << "\n";
  
  return 0;
}