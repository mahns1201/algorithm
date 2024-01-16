https://www.acmicpc.net/problem/11650

#include <bits/stdc++.h>
using namespace std;

/*
	날짜: 2024-01-10
	횟수: 1
    특이사항: cmp로 정렬할 때 조건을 어떻게 주어야 하는지 명확하게 파악 할 것
*/

int n, a, b;
vector<pair<int, int>> v;

void printV(vector<pair<int, int>> V) {
    for (auto i: V) {
        cout << i.first << " " << i.second << "\n";
    }
}

bool cmp(pair<int, int> x, pair<int, int> y) {
    if (x.first == y.first) {
        return x.second < y.second;
    }

    return x.first < y.first;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;

    for (int i=0; i<n; i++) {
        cin >> a >> b;
        v.push_back({a, b});
    }

    sort(v.begin(), v.end(), cmp);

    printV(v);

    return 0;
}