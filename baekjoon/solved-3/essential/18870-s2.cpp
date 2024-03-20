#include <bits/stdc++.h>
using namespace std;

/*
	날짜: 2024-03-21
	횟수: 1
    메모: lower_bound() 함수
*/

int n, t;
vector<int> v, vv;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> t;
        v.push_back(t);
        vv.push_back(t);
    }
    sort(vv.begin(), vv.end());
    vv.erase(unique(vv.begin(), vv.end()), vv.end());

    for(int i=0; i<n; i++) {
        auto it = lower_bound(vv.begin(), vv.end(), v[i]);
        cout << it - vv.begin() << ' ';
    }
    cout << '\n';

    return 0;
}