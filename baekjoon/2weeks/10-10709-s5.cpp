// https://www.acmicpc.net/problem/10709

#include <bits/stdc++.h>
using namespace std;

int y, x;
int maxV = 104;
int ret[104][104];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> y >> x;
    string ts;
    for (int i=0; i<y; i++){
        cin >> ts;
        for (int j=0; j<x; j++) {
            if (ts[j] == 'c') ret[i][j] = 0;
            if (ts[j] == '.') ret[i][j] = -1;
        }
    }

    for (int i=0; i<y; i++) {
        for (int j=0; j<x; j++) {
            if (j == 0) continue;
            if (ret[i][j] == 0) continue;
            if (ret[i][j] == -1 && ret[i][j-1] != -1) ret[i][j] = ret[i][j-1] + 1;
        }
    }

    for (int i=0; i<y; i++) {
        for (int j=0; j<x; j++) {
            cout << ret[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}