#include <bits/stdc++.h>
using namespace std;

/*
	날짜: 2024-03-27
	횟수: 1
    메모: 다시 풀기
*/

const int MAX_N = 128;
int n, t, white, blue;
int mp[MAX_N][MAX_N];

// 흰색 == 0, 파란색 == 1
void divide_qonquer(int y, int x, int depth) {
    int temp_blue_cnt = 0;
    for(int i=y; i<y+depth; i++) {
        for(int j=x; j<x+depth; j++) {
            if(mp[i][j]) temp_blue_cnt++;
        }
    }

    if(temp_blue_cnt == 0) white++;
    else if(temp_blue_cnt == depth*depth) blue++;
    else {
        divide_qonquer(y, x, depth/2);
        divide_qonquer(y, x+depth/2, depth/2);
        divide_qonquer(y+depth/2, x, depth/2);
        divide_qonquer(y+depth/2, x+depth/2, depth/2);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> mp[i][j];
        }
    }

    divide_qonquer(0, 0, n);
    cout << white << '\n';
    cout << blue << '\n';

    return 0;
}
