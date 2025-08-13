// https://www.acmicpc.net/problem/2630

#include <bits/stdc++.h>
using namespace std;

/*
	날짜: 2025-08-13
	횟수: 2
    메모: 1992와 유사한 문제
*/
const int MAX = 129;
int n, mp[MAX][MAX], ret0, ret1;

void calc(int val) {
    if (val == 0) {
        ret0++;
    } else {
        ret1++;
    }
}

bool check(int y, int x, int size) {
    int idx = mp[y][x];

    for (int i=y; i<y+size; i++) {
        for (int j=x; j<x+size; j++) {
            if (idx != mp[i][j]) {
                return false;
            }
        }
    }
    
    return true;
}

void quad(int y, int x, int size) {
    if (size == 1) {
        calc(mp[y][x]);
        return;
    }

    if (check(y, x, size)) {
        calc(mp[y][x]);
        return;
    }

    quad(y, x, size/2);
    quad(y, x+size/2, size/2);
    quad(y+size/2, x, size/2);
    quad(y+size/2, x+size/2, size/2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> mp[i][j];
        }
    }

    quad(0, 0, n);

    cout << ret0 << "\n" << ret1 << "\n";

    return 0;
}

/*
	날짜: 2024-03-27
	횟수: 1
    메모: 다시 풀기
*/
// const int MAX_N = 128;
// int n, t, white, blue;
// int mp[MAX_N][MAX_N];

// // 흰색 == 0, 파란색 == 1
// void divide_qonquer(int y, int x, int depth) {
//     int temp_blue_cnt = 0;
//     for(int i=y; i<y+depth; i++) {
//         for(int j=x; j<x+depth; j++) {
//             if(mp[i][j]) temp_blue_cnt++;
//         }
//     }

//     if(temp_blue_cnt == 0) white++;
//     else if(temp_blue_cnt == depth*depth) blue++;
//     else {
//         divide_qonquer(y, x, depth/2);
//         divide_qonquer(y, x+depth/2, depth/2);
//         divide_qonquer(y+depth/2, x, depth/2);
//         divide_qonquer(y+depth/2, x+depth/2, depth/2);
//     }
// }

// int main() {
//     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//     cin >> n;
//     for(int i=0; i<n; i++) {
//         for(int j=0; j<n; j++) {
//             cin >> mp[i][j];
//         }
//     }

//     divide_qonquer(0, 0, n);
//     cout << white << '\n';
//     cout << blue << '\n';

//     return 0;
// }
