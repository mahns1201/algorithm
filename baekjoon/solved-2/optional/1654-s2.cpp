#include <bits/stdc++.h>
using namespace std;

/*
	날짜: 2024-01-30
	횟수: 1
    특이사항: 1920 문제와 함께 다시 풀어볼 것.
*/

int k, n;
long long ll, mid, rr;
int max_val = 0;
int ret = 0;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> k >> n;
    
    int arr[k];

    for (int i=0; i<k; i++) {
        cin >> arr[i];
        max_val = max(arr[i], max_val);
    }
    sort(arr, arr+k);

    ll = 1;
    rr = max_val;
    while (ll <= rr) {
        mid = (ll + rr) / 2;

        int cnt = 0;
        for (int i=0; i<k; i++) {
            cnt += arr[i] / mid;
        }

        if (n <= cnt) {
            ll = mid+1;
            if (ret < mid) ret = mid;
        } else {
            rr = mid-1;
        }
    }
    
    cout << ret << "\n";

    return 0;
}