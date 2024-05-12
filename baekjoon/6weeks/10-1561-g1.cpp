#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
    날짜: 2024-05-12
	횟수: 1
    메모: 아오 진짜 개열받는다 다시 풀자...
*/

ll n, m, current_time = 10000000000000, result;
ll m_arr[10004];

ll get_usage(ll ct) {
	ll usage = 0;
	for (int i=0; i<m; i++) {
		usage += ct / m_arr[i];
		++ usage;
	}
	return usage;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i=0; i<m; i++) cin >> m_arr[i];

	if (n <= m) {
		cout << n << '\n';
		return 0;
	}

	ll left = 1, right = 10000000000000;
	
	while (left <= right) {
		ll ct = (left+right) / 2; // current_time
		ll usage = get_usage(ct);

		if (n <= usage) { // ct에 모든 n명을 수용가능하다.
			// if (current_time > ct) current_time = ct;
			current_time = ct;
			right = ct - 1;
		} else {
			left = ct + 1;
		}
	}

	ll curr_usage = get_usage(current_time - 1);
	ll left_people = n - curr_usage;

	for (int i=0; i<m; i++) {
		if (current_time % m_arr[i] == 0) {
			-- left_people;
			result = i+1;
		}

		if (left_people == 0) break;
	}
	
	cout << result << "\n";

	return 0;
}