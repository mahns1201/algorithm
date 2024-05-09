#include <bits/stdc++.h>
using namespace std;

/*
    날짜: 2024-05-10
	횟수: 1
	메모: 자만하지 말고 문제를 잘 읽자.
*/

int n;
long long atk, t, a, h, result = 123456000000000004;
struct T {
	long long t, a, h;
};
T arr[123456];
T arr_copy[123456];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> atk;
	for (int i=0; i<n; i++) {
		cin >> t >> a >> h;
		arr[i] = {t, a, h};
		arr_copy[i] = {t, a, h};
	}

	int i = 0;
	long long left = 0, right = 123456000000000004;

	while (left <= right) {
		long long hp = (left + right) / 2;
		long long curr_atk = atk, curr_hp = hp;
		bool battle_result = true;
		for (i; i<n; i++) {
			if (curr_hp <= 0) {
				battle_result = false;
			}
			if (arr[i].t == 1) {
				long long e_cnt = arr[i].h % curr_atk == 0 ? arr[i].h / curr_atk : arr[i].h / curr_atk + 1;
				long long h_cnt = curr_hp % arr[i].a == 0 ? curr_hp / arr[i].a : curr_hp / arr[i].a + 1;
				
				if (e_cnt <= h_cnt) {
					curr_hp -= arr[i].a * (e_cnt - 1);
				}
				else {
					battle_result = false;
					break;
				}
			} 
			else {
				curr_atk += arr[i].a;
				curr_hp += arr[i].h;
				if (curr_hp > hp) curr_hp = hp;
			}
		}

		i = 0;
		memcpy(&arr, &arr_copy, sizeof(arr_copy));

		if (battle_result) {
			result = min(result, hp);
			right = hp - 1;
		} else {
			left = hp + 1;
		}
	}

	cout << result << '\n';	

	return 0;
}