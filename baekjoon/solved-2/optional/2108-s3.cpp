#include <bits/stdc++.h>
using namespace std;

/*
	날짜: 2024-02-03
	횟수: 1
*/

const int max_nv = 8004;
int n, t; 
double total;
int cnt_arr[max_nv];
vector<int> v;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    int arr[n];
    
    for (int i=0; i<n; i++) {
        cin >> t;
        arr[i] = t;
        total += t;
        cnt_arr[t+4000]++;
    }
    sort(arr, arr+n);

    int max_v = -987654321;
    cout << "----------------------\n";
    for (int i=0; i<8001; i++) {
        max_v = max(max_v, cnt_arr[i]);
    }

    for (int i=0; i<8001; i++) {
        if (cnt_arr[i] == max_v) {
            v.push_back(i - 4000);
        }
    }

    int third_value = v.size() == 1 ? v[0] : v[1];

    cout << floor(total / n + 0.5) << "\n";
    cout << arr[n/2] << "\n";
    cout << third_value << "\n";
    cout << arr[n-1] - arr[0] << "\n";

    return 0;
}