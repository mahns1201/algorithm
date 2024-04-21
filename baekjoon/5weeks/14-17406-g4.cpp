#include <bits/stdc++.h>
using namespace std;

/*
	날짜: 2024-04-22
	횟수: 1
*/

const int MAX_N = 54;
int n, m, rot_cnt, r, c, s, result = 987654321;
int mp[MAX_N][MAX_N];
int _mp[MAX_N][MAX_N];
struct T {
	int r, c, s;
};
vector<int> order;
vector<T> v;

void rotate(int tr, int tc, int ts) {
	int temp = mp[tr][tc];
	for(int i=tr+1; i<tr+2*ts+1; i++) mp[i-1][tc] = mp[i][tc];
	for(int i=tc; i<tc+2*ts+1; i++) mp[tr+2*ts][i] = mp[tr+2*ts][i+1];
	for(int i=tr+2*ts; i>tr-1; i--) mp[i][tc+2*ts] = mp[i-1][tc+2*ts];
	for(int i=tc+2*ts; i>tc; i--) mp[tr][i] = mp[tr][i-1];
	mp[tr][tc+1] = temp;
}

void cal_result() {
	for(int i=0; i<n; i++) {
		int _sum = 0;
		for(int j=0; j<m; j++) {
			_sum += mp[i][j];
		}
		result = min(result, _sum);
	}
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> rot_cnt;

	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin >> mp[i][j];
		}
	}
	memcpy(&_mp, &mp, sizeof(mp));

	for(int i=0; i<rot_cnt; i++) {
		cin >> r >> c >> s;
		order.push_back(i);
		v.push_back({r-1, c-1, s});
	}

	do {
		memcpy(&mp, &_mp, sizeof(_mp));
		for(int i=0; i<rot_cnt; i++) {
			for(int t=0; t<v[order[i]].s; t++) {
				rotate(v[order[i]].r-v[order[i]].s+t, v[order[i]].c-v[order[i]].s+t, v[order[i]].s-t);
			}
		}
		cal_result();
		
	} while(next_permutation(order.begin(), order.end()));

	cout << result << '\n';
    return 0;
}