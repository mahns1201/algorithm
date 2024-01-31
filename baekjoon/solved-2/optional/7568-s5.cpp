#include <bits/stdc++.h>
using namespace std;

/*
	날짜: 2024-01-31
	횟수: 1
    특이사항: 덩치가 더 큰 조건을 잘 읽어보자...
*/

int n;
int ret[54];
vector<pair<int,int>> v;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }

    for (int i=0; i<n; i++) {
        int curr = 1;
        for (int j=0; j<n; j++) {
            if (v[i].first < v[j].first && v[i].second < v[j].second) curr++;
        }
        cout << curr << " ";
    }
    cout << "\n";

    return 0;
}