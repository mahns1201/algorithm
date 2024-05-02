#include <bits/stdc++.h>
using namespace std;

/*
    날짜: 2024-05-02
	  횟수: 1
*/

const int MAX_VAL = 10000 * 100000;
int n, m, _max, result = MAX_VAL;
int arr[100004];

bool check(int ret) {
	if(_max > ret) return false;
	
	int cnt = 1; // 인출 횟수
	int curr = ret; // 가장 처음에는 인출 1회 분량을 가지고 있다.

	for(int i=0; i<n; i++) {
		if(curr >= arr[i]) curr -= arr[i];
		else {
			cnt += 1;
			curr = ret;
			curr -= arr[i];
		}
	}

	return cnt <= m; // 인출 횟수보다 최대 인출 횟수가 커야 true다.
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i=0; i<n; i++) {
		cin >> arr[i];
		_max = max(_max, arr[i]);
	}

	int left = _max, right = MAX_VAL;

	while(left <= right) {
		int mid = (left + right) / 2;
		
		if(check(mid)) {
			result = min(result, mid);
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}

	cout << result << '\n';

	return 0;
}