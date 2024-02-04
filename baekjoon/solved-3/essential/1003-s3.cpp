#include <bits/stdc++.h>
using namespace std;

/*
	날짜: 2024-02-04
	횟수: 1
*/

int t, tt, max_n;
vector<int> vv;
vector<pair<int, int>> v;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;

    for (int i=0; i<t; i++) {
        cin >> tt;
        max_n = max(max_n, tt);
        vv.push_back(tt);
    }

    v.push_back({1, 0});
    v.push_back({0, 1});
    
    for (int i=2; i<=max_n; i++) {
        v.push_back({v[i-2].first + v[i-1].first, v[i-2].second + v[i-1].second});
    }

    for (int i=0; i<vv.size(); i++) {
        cout << v[vv[i]].first << " " << v[vv[i]].second << "\n";
    }

    return 0;
}