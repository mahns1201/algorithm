#include <bits/stdc++.h>
using namespace std;

/*
	날짜: 2024-01-20
	횟수: 1
*/

int n, x, y;
queue<pair<int, int>> q;
int arr[104];
// vector<int> ret;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;

    for (int i=0; i<n; i++) {
        cin >> x >> y;
        for (int j=0; j<x; j++) {
            int t;
            cin >> t;
            if (j == y) {
                q.push({t, j+1});
            } else {
                q.push({t, 0});
            }
            arr[j] = t;
        }

        sort(arr, arr+104, greater<>());

        int k = 1;
        for (int i=0; i<x; i++) {
            if (!k) break;
            while(k) {
                int f, s;
                tie(f, s) = q.front(); q.pop();
                if (f == arr[i]) {
                    if (s == y+1) {
                        cout << i+1 << "\n";
                        // ret.push_back(i+1);
                        memset(arr, 0, sizeof(arr));
                        while(q.size()) q.pop();
                        k = 0;
                    }
                    // cout << f << " " << s << " " << y << "\n";
                    // break;
                    break;
                } else {
                    q.push({f, s});
                }
            }
        }
    }

    // for (auto i: ret) {
    //     cout << i << "\n";
    // }

    return 0;
}