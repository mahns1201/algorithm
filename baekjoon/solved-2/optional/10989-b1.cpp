#include <bits/stdc++.h>
using namespace std;

/*
	날짜: 2024-01-19
	횟수: 1
    특이사항: 진짜 다시 꼭 풀어보자...!
*/

int n;
int arr[10000];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;

    for (int i=0; i<n; i++) {
        short t;
        cin >> t;

        arr[t-1] += 1;
    }

    for (short i=0; i<10000; i++) {
        for (int j=0; j<arr[i]; j++) {
            cout << i+1 << "\n";
        }
    }

    return 0;
}