#include <bits/stdc++.h>
using namespace std;

/*
	날짜: 2024-02-06
	횟수: 1
*/

int n, k, result;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    int arr[n];
    for (int i=0; i<n; i++) cin >> arr[i];

    for (int i=n-1; i>=0; i--) {
        int numbers = k / arr[i];
        if (numbers > 0) {
            k -= (numbers) * arr[i];
            result += numbers;
        }
    }

    cout << result << "\n";

    return 0;
}