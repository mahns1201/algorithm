#include <bits/stdc++.h>
using namespace std;

/*
	날짜: 2024-02-03
	횟수: 1
*/

int n, m, b;
int result1 = 987654321;
int result2;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> b;
    int arr[n][m];
    int total = b;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> arr[i][j];
            total+= arr[i][j];
        }
    }

    int max_height = total / (n*m);

    for (int h=0; h<=max_height; h++) {
        int ret = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                int blocks = arr[i][j] - h;
                if (blocks == 0) continue;
                else if (blocks > 0) ret += blocks*2;
                else ret += -1*blocks;
            }
        }
        
        result1 = min(result1, ret);
        if (result1 == ret) result2 = h;
    }

    cout << result1 << " " << result2 << "\n";

    return 0;
}