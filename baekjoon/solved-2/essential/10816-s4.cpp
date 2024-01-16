#include <bits/stdc++.h>
using namespace std;

/*
	날짜: 2024-01-11
	횟수: 1
*/

const int prefix = 10000000;
int n, m, x, y;
int arr[20000004];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;

    for (int i=0; i<n; i++) {
        cin >> x;
        if (x < 0) {
            x = -1 * x + prefix;
        }
        arr[x]++;
    }

    cin >> m;
    for (int j=0; j<m; j++) {
        cin >> y;
        if (y < 0) {
            y = -1 * y + prefix;
        }
        cout << arr[y] << " ";
    }
    cout << "\n";


    return 0;
}