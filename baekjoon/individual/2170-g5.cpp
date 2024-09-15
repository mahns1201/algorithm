#include <bits/stdc++.h>
using namespace std;

/*
    날짜: 2024-09-15
    횟수: 1
*/

int n, x, y, l, r, result;
vector<pair<int, int>> v;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> x >> y;
        v.push_back({x, y});
    }

    sort(v.begin(), v.end());

    l = v[0].first;
    r = v[0].second;
    result = r - l;
    for(int i=1; i<n; i++) {
        if(v[i].second < r) {
            continue;
        } else if(v[i].first < r && v[i].second >= r) {
            result += v[i].second - r;
            r = v[i].second;
        } else {
            l = v[i].first;
            r = v[i].second;
            result += r - l;
        }
    }

    cout << result << "\n";

    return 0;
}