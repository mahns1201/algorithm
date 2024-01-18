#include <bits/stdc++.h>
using namespace std;

/*
	날짜: 2024-01-19
	횟수: 1
*/

int n, a, b;
vector<pair<int, int>> v;

bool cmp(pair<int, int> x, pair<int, int> y) {
    if (x.second == y.second) return x.first < y.first;
    return x.second < y.second;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;

    for (int i=0; i<n; i++) {
        cin >> a >> b;
        v.push_back({a, b});
    }

    sort(v.begin(), v.end(), cmp);

    for (int i=0; i<n; i++) {
        cout << v[i].first << " " << v[i].second << "\n";
    }

    return 0;
}