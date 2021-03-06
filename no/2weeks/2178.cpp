#include <bits/stdc++.h>
using namespace std;

string input;
int n, m;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int adj[104][104];
int visited[104][104];
int ret = 0;

void bfs(int y, int x) {
  visited[0][0] = 1;
  queue<pair<int, int>> q;
  q.push({y, x});
  while(q.size()){
    pair<int, int> here = q.front(); q.pop();
    for(int i=0; i<4; i++) {
      int ny = here.first + dy[i];
      int nx = here.second + dx[i];
      
      if(ny < 0 || nx < 0 || n <= ny || m <= nx || adj[ny][nx] == 0) continue; 
      if (visited[ny][nx]) continue;
      q.push({ny, nx});
      visited[ny][nx] = visited[here.first][here.second] + 1;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> n >> m;
  for (int i=0; i<n; i++) {
    cin >> input;
    for (int j=0; j<input.size(); j++) {
      adj[i][j] = atoi(input.substr(j, 1).c_str());
    }
  }

  bfs(0, 0);
  cout << visited[n-1][m-1] << "\n";

  return 0;  
}

// void dfs(int y, int x) {
//   visited[y][x] = 1;
//   ret ++;
//   // cout << "visited: " << y << ", " << x << "\n";
//   if (y == 3 && x == 5) cout << ret-1 << "\n";
  
//   for(int i=0; i<4; i++) {
//     int ny = y + dy[i];
//     int nx = x + dx[i];
//     // cout << "ny, nx: " << ny << ", " << nx << "\n";

//     if(ny >= 0 && nx >= 0 && !visited[ny][nx] && adj[ny][nx]) {
//       dfs(ny, nx);
//     }
//   }
// }

/*
4 6 
1 0 1 1 1 1
1 0 1 0 1 0
1 0 1 0 1 1
1 1 1 0 1 1

4 6 
1 1 0 1 1 0
1 1 0 1 1 0
1 1 1 1 1 1
1 1 1 1 0 1
*/