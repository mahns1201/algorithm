#include <bits/stdc++.h>
using namespace std;

/*
	날짜: 2024-02-05
	횟수: 1
*/

int n, m, t1, t2;
int pre_sum[100004];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;

    for (int i=1; i<n+1; i++) {
        cin >> pre_sum[i];
        pre_sum[i] += pre_sum[i-1];
    }

    while (m > 0) {
        m--;
        cin >> t1 >> t2;
        cout << pre_sum[t2] - pre_sum[t1-1] << "\n";
    }

    return 0;
}