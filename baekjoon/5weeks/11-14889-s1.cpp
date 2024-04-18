#include <bits/stdc++.h>
using namespace std;

/*
	날짜: 2024-04-19
	횟수: 1
*/

const int MAX_N = 20;
int n, result = 987654321;
int mp[MAX_N][MAX_N];
vector<int> team1, team2;

int get_bit_cnt(int num) {
	int cnt = 0;
	team1.clear();
	team2.clear();
	for(int i=0; i<n; i++) {
		if(num & (1 << i)) {
			team1.push_back(i);
			cnt++;
		}else {
			team2.push_back(i);
		}
	}
	return cnt;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin >> mp[i][j];
		}
	}
    
	for(int i=0; i<pow(2, n); i++) {
		int bit_cnt = get_bit_cnt(i);
		int team1_cnt = 0;
		int team2_cnt = 0;
		if(bit_cnt == n/2) {
			for(int i=0; i<n/2; i++) {
				for(int j=0; j<n/2; j++) {
					if(i==j) continue;
					team1_cnt += mp[team1[i]][team1[j]];
				}
			}

			for(int i=0; i<n/2; i++) {
				for(int j=0; j<n/2; j++) {
					if(i==j) continue;
					team2_cnt += mp[team2[i]][team2[j]];
				}
			}

			// cout << team1_cnt << ' ' << team2_cnt << '\n';
			result = min(result, abs(team1_cnt-team2_cnt));
		}
	}

	cout << result << '\n';
	// int cnt = 0;
	// for(int i=0; i<4; i++) {
	// 	if(1 &(1 << i)) cnt++;
	// }
	// cout << cnt << '\n';

	// for(int i=0; i<3; i++) {
	// 	for(int j=0; j<3; j++) {
	// 		if(i==j) continue;
	// 		cout << i << ' ' << j << '\n';
	// 	}
	// }

    return 0; 
}