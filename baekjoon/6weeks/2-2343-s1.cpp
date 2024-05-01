#include <bits/stdc++.h>
using namespace std;


/*
    날짜: 2024-05-01
	  횟수: 1
    메모: check 다시 구현하기... 왜 틀렸을까?
*/

int n, m, result, _sum, _max;
int arr[100004];

bool check(int ret) {
	if(_max > ret) return false;  
    int temp = ret;
    
	int cnt = 0;
    for(int i=0; i<n; i++) {
        if(ret-arr[i] < 0){
            ret = temp;
            cnt++;
        }
        ret -= arr[i];
    }
    if(ret != temp) cnt++; 
    return cnt <= m;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	
	for(int i=0; i<n; i++) {
		cin >> arr[i];
		_sum += arr[i];
		_max = max(_max, arr[i]);
	}

	int left = 1, right = _sum;
	
	while(left <= right) {
		int mid = (left+right) / 2;
		if(check(mid)) {
			result = mid;
			right = mid - 1;
		}else {
			left = mid + 1;
		}
	}

	cout << result << '\n';

	return 0;
}