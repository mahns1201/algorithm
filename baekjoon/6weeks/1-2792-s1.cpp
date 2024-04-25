#include <bits/stdc++.h>
using namespace std;

/*
    날짜: 2024-04-26
	  횟수: 1
    메모: 이분탐색을 왜, 어떻게 적용했는지 생각하기
*/

int n, m, result = 987654321;
int arr[300000];

bool search(int estimate_val) {
	if(estimate_val == 0) return false;
	int ret = 0;
	for(int i=0; i<m; i++) {
		ret += arr[i] / estimate_val;
		if(arr[i] % estimate_val) ret++;
	}

	return ret <= n;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	
	int left = 0, right = 0, mid;
	
	for(int i=0; i<m; ++i) {
		cin >> arr[i];
		right = max(right, arr[i]);
	}
	
	while(left <= right) {
		mid = (left+right) / 2;

		if(search(mid)) {
			result = min(result, mid);
			right = mid - 1;
		}else {
			left = mid + 1;
		}
	}
	
	cout << result << '\n';
    
	return 0;
}