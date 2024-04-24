#include <bits/stdc++.h>
using namespace std;

/*
	날짜: 2024-04-23
	횟수: 1
*/

const int MAX_N = 1004;
int n, t, t1, t2, result;
string s;
int mp[MAX_N][8];
int can_rotate_by_right[MAX_N];
int can_rotate_by_left[MAX_N];

void rotate(int row, int dir) {
	if(dir == 1) { // 시계
		int _temp = mp[row][7];
		for(int i=7; i>0; i--) {
			mp[row][i] = mp[row][i-1];
		}
		mp[row][0] = _temp;
	}else { // 반시계
		int _temp = mp[row][0];
		for(int i=1; i<8; i++) {
			mp[row][i-1] = mp[row][i];
		}
		mp[row][7] = _temp;
	}
}

void get_can_rotate() {
	memset(can_rotate_by_right, 0, sizeof(can_rotate_by_right));
	memset(can_rotate_by_left, 0, sizeof(can_rotate_by_left));

	for(int i=0; i<n-1; i++) {
		if(mp[i][2] != mp[i+1][6]) can_rotate_by_right[i] = 1;
	}

	for(int i=1; i<n; i++) {
		if(mp[i-1][2] != mp[i][6]) can_rotate_by_left[i] = 1;
	}
}

void check_left_rotate(int row, int dir) {
	if(row-1 < 0) return;
	if(!can_rotate_by_right[row-1]) return;

	rotate(row-1, dir*-1);
	check_left_rotate(row-1, dir*-1);

	return;
}

void check_right_rotate(int row, int dir) {
	if(row+1 >= n) return;
	if(!can_rotate_by_left[row+1]) return;

	rotate(row+1, dir*-1);
	check_right_rotate(row+1, dir*-1);

	return;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	
	for(int i=0; i<n; i++) {
		cin >> s;
		for(int j=0; j<8; j++) {
			mp[i][j] = s[j]-'0';
		}
	}

	cin >> t;

	for(int i=0; i<t; i++) {
		cin >> t1 >> t2;
		get_can_rotate();
		rotate(t1-1, t2);
		check_left_rotate(t1-1, t2);
		check_right_rotate(t1-1, t2);
	}

	for(int i=0; i<n; i++) {
		if(mp[i][0] == 1) result++;
	}

	cout << result << '\n';

    return 0;
}