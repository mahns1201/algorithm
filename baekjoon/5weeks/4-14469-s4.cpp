#include <bits/stdc++.h>
using namespace std;

/*
    날짜: 2024-03-31
	횟수: 1
*/

int n, a, b, ret;
vector<pair<int, int>> v;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a >> b;
        v.push_back({a, b});
    }

    sort(v.begin(), v.end());

    int curr = v[0].first;
    for(auto it: v) {
        if(it.first >= curr) {
            curr = it.first;
            curr += it.second;
        }else {
            curr += it.second;
        }
    }

    cout << curr << '\n';
    return 0;
}