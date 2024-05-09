#include <bits/stdc++.h>
using namespace std;

/*
    날짜: 2024-05-10
	횟수: 1
	메모: 자만하지 말고 문제를 잘 읽자.
*/

int a, b, temp;
vector<int> a_v, b_v;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> a >> b;
	int ret_a = a, ret_b = b;
	
	for (int i=0; i<a; i++) {
		cin >> temp;
		a_v.push_back(temp);
	}

	for (int i=0; i<b; i++) {
		cin >> temp;
		b_v.push_back(temp);
	}

	sort(a_v.begin(), a_v.end());
	sort(b_v.begin(), b_v.end());

	for(int it: b_v) {
		int left = 0, right = a-1;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (a_v[mid] == it) {
				ret_a -= 1;
				break;
			}
			else if (a_v[mid] > it) right = mid - 1;
			else left = mid + 1;
		}
	}

	for(int it: a_v) {
		int left = 0, right = b-1;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (b_v[mid] == it) {
				ret_b -= 1;
				break;
			}
			else if (b_v[mid] > it) right = mid - 1;
			else left = mid + 1;
		}
	};

	cout << ret_a + ret_b << '\n';

	return 0;
}