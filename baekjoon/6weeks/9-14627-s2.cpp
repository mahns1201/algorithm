#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
    날짜: 2024-05-11
	횟수: 1
    메모: left, right, result 범위에 대해 생각.
*/

ll s, c, s_sum, s_max, result = 9999999999999999;
ll s_arr[1000004];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> s >> c;
	for (int i=0; i<s; i++) {
		cin >> s_arr[i];
		s_sum += s_arr[i];
		if (s_max < s_arr[i]) s_max = s_arr[i];
	}

	ll left = 1, right = 1000000000;
	while (left <= right) {
		ll mid = (left + right) / 2; // 파를 자르는 기준
		ll c_cnt = 0;

		if (s_max < mid) { // 자르는 기준이 파의 최대 길이보다 크면 넘긴다.
			// cout << "[!]\n"; 
			right = mid - 1;
			continue;
		}

		for (int i=0; i<s; i++) {
			c_cnt += s_arr[i] / mid;
		}

		// cout << "[0] " << mid << ' ' << c_cnt << '\n';

		if (c <= c_cnt) { // 팔 수 있다.
			result = mid;
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}

	cout << s_sum - (c*result) << '\n';

	return 0;
}