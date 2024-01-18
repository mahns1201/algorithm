#include <bits/stdc++.h>
using namespace std;

/*
	날짜: 2024-01-19
	횟수: 1
*/

int n;
float mm, ret;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    mm = floor(n*0.15 + 0.5);

    if (n == 0) {
        cout << 0 << "\n";
        exit(0);
    }

    int arr[n];
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr+n);

    for (int i=mm; i<n-mm; i++) {
        ret += arr[i];
    }

    cout << floor((ret / (n-(mm*2))) + 0.5) << "\n";
    
    return 0;
}