#include <bits/stdc++.h>
using namespace std;

/*
	날짜: 2024-02-04
	횟수: 1
*/

int n, result;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    int arr[n];
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr+n, greater<>());

    for (int i=0; i<n; i++) {
        result += arr[i] * (i+1);
    }
    cout << result << "\n";

    return 0;
}