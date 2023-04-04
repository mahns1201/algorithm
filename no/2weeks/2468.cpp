https://www.acmicpc.net/problem/2468

#include <bits/stdc++.h>
using namespace std;

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int N, ret = 1;
int adj[104][104];
int flood[104][104];
int visited[104][104];
int answer[104];
void dfs(int y, int x, int k) {
  visited[y][x] = 1;  
  
  for (int i=0; i<4; i++) {
    int ny = y +dy[i];
    int nx = x +dx[i];

    if (ny < 0 || nx < 0 || N-1 <  ny || N-1 < nx ){
      continue;
    }
    if (adj[ny][nx] <= k || visited[ny][nx]) {
      continue;
    }
    dfs(ny, nx, k);
  }
  return;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> N;

  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      cin >> adj[i][j];
    }
  }

  for (int k=1; k<100+1; k++) {
    // array 초기화하는 법 숙지!
    fill(&visited[0][0], &visited[0][0] + 104 * 104, 0);

    int cnt = 0;
    
    for (int i=0; i<N; i++) {
      for (int j=0; j<N; j++) {
        if (k < adj[i][j] && !visited[i][j]) {
          dfs(i, j, k);
          cnt++;
        }
      }
    }

    // max 초기화 숙지!
    ret = max(ret, cnt);    
  }

  cout << ret << "\n";

  return 0;
}

