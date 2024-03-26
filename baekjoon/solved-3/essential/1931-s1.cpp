#include <bits/stdc++.h>
using namespace std;

/*
	날짜: 2024-03-27
	횟수: 1
    메모: 그리디 시작. 다시 풀어보기.
*/

int n, a, b;
vector<pair<int, int>> v;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> a >> b;
        v.push_back({b, a});
    }

    sort(v.begin(), v.end());

    int curr = 0;
    int ret = 0;
    for(int j=0; j<n; j++) {
        if(curr > v[j].first) continue;
        if(curr > v[j].second) continue;
        curr = v[j].first;
        ret++;
    }

    cout << ret << '\n';

    return 0;
}