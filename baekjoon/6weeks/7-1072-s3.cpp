#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
    날짜: 2024-05-11
	횟수: 1
*/

ll x, y, result = 1000000000;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> x >> y;
	ll z = y * 100 / x;
	ll left = 1, right = result;
	bool is_change = false;

	while(left <= right) {
	int games = (left+right) / 2; // games만큼 더 했다는 뜻
	ll nx = x + games;
	ll ny = y + games;
	ll nz = ny * 100 / nx;

	if (z != nz) {
		if (result > games) result = games;
		right = games - 1;
		is_change = true;
	} else {
		left = games + 1;
	}
	}

	if (is_change) cout << result << '\n';
	else cout << -1 << '\n';

	return 0;
}