#include <bits/stdc++.h>
using namespace std;

/*
	날짜: 2024-01-17
	횟수: 1*
    특이사항: 꼭 다시 풀어봐야 한다...
*/

const int max_n = 54;
int n, m;
string s;
char arr[max_n][max_n];
int ret = 987654321;

string wb[8] = {
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW"
};
string bw[8] = {
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB"
};

int check_wb(int x, int y) {
    int temp = 0;
    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            if (arr[i+x][j+y] != wb[i][j]) {
                temp++;
            }
        }
    }
    return temp;
}

int check_bw(int x, int y) {
    int temp = 0;
    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            if (arr[i+x][j+y] != bw[i][j]) {
                temp++;
            }
        }
    }
    return temp;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;

    for (int i=0; i<n; i++) {
        cin >> s;
        for (int j=0; j<s.size(); j++) {
            arr[i][j] = s[j];
        }
    }

    for (int i=0; i<n-7; i++) {
        for (int j=0; j<m-7; j++) {
            // cout << i << " " << j << "\n";
            ret = min(ret, check_bw(i, j));
            ret = min(ret, check_wb(i, j));
            // cout << check_bw(i, j) << " " << check_wb(i, j) << "\n";
        }
    }

    cout << ret << "\n";

    // for (int i=0; i<n; i++) {
    //     for (int j=0; j<m; j++) {
    //         cout << arr[i][j] << " ";
    //     }    
    //     cout << "\n";
    // }
    return 0;
}