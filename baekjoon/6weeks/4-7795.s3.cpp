#include <bits/stdc++.h>
using namespace std;

/*
    날짜: 2024-05-02
	  횟수: 1
*/


int t, n, m;
int arr_a[20004], arr_b[20004];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> t;

	while(t) {
		int result = 0;
		cin >> n >> m;
		memset(arr_a, 0, sizeof(arr_a));
		memset(arr_b, 0, sizeof(arr_b));
		for(int i=0; i<n; i++) cin >> arr_a[i];
		for(int i=0; i<m; i++) cin >> arr_b[i];
		sort(arr_a, arr_a + n);
		sort(arr_b, arr_b + m, greater<>());

		for(int i=0; i<n; i++) {
			int ret = 987654321;
			int left = 0, right = m-1;

			while(left <= right) {
				int mid = (left + right) / 2;
				
				if(arr_a[i] > arr_b[mid]) { // 먹을 수 있다.
					ret = min(ret, mid);
					right = mid - 1;
				} else {
					left = mid + 1;
				}
			}

			// 먹을 수 있는 최소값 즉 ret index에 있는 애부터 오른쪽까지 다 먹을 수 있음.
			if (ret == 987654321) ret = m;
			result += m - ret;
		}
		cout << result << '\n';
		t--;
	}

	return 0;
}