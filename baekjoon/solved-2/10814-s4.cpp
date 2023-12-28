// https://www.acmicpc.net/problem/10814

#include <bits/stdc++.h>
using namespace std;

/*
    날짜: 2023-12-28
	횟수: 1
    메모: stable-sort unstable-sort 개념 정리 필요. 추가로 정렬 알고리즘 공부 다시 하자...
*/

int n, m;
string s;
vector<pair<int, string>> v;

bool cmp(pair<int, string> a, pair<int, string> b) {
    return a.first < b.first;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;

    for (int i=0; i<n; i++) {
        cin >> m >> s;
        v.push_back({m, s});
    }

    stable_sort(v.begin(), v.end(), cmp);
    
    for (auto it: v) cout << it.first << " " << it.second << "\n";
    
    return 0;
}