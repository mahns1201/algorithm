#include <bits/stdc++.h>
using namespace std;

/*
	날짜: 2024-01-17
	횟수: 1*
    특이사항: binary search 구현 연습
*/

int n, m;
long long x, y;
long long arr[100004];

void binary_search(int x) {
    int left = 0, mid = 0, right = n - 1;

    while (left <= right) {
        mid = (left + right) / 2;

        // 탈출 조건 : a_array에서 x를 찾은 경우
        if (arr[mid] == x) {
            cout << 1 << "\n";
            return;
        } else if (arr[mid] > x) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    // 이분 탐색이 끝날 때까지 x를 찾지 못했다면 0(false)를 출력한다.
    cout << 0 << "\n";

    return;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;

    for (int i=0; i<n; i++) {
        cin >> x;
        arr[i] = x;
    }

    sort(arr, arr+n);

    cin >> m;
    for (int j=0; j<m; j++) {
        cin >> y;
        // if (y < 0) {
        //     y = -1 * y + prefix;
        // }
        // cout << arr[y] << "\n";

        // bool t = check(y);
        // cout << t << "\n";
        binary_search(y);
    }

    

    return 0;
}