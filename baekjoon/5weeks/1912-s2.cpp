#include <bits/stdc++.h>
using namespace std;

/*
	날짜: 2024-05-15
	횟수: 1
*/

int n, t, _sum, result = -1004;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
    for (int i=0; i<n; i++) {
        cin >> t;
        _sum += t;
        result = max(result, _sum);
        if (_sum < 0) _sum = 0;
    }
    cout << result << '\n';
	return 0;
}