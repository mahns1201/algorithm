#include <bits/stdc++.h>
using namespace std;

/*
    날짜: 2024-03-29
	횟수: 1
    메모: pq 사용법 숙지
*/

int n, price, day, ret;
vector<pair<int, int>> v;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    
    for(int i=0; i<n; i++) {
        cin >> price >> day;
        v.push_back({day, price});
    }

    sort(v.begin(), v.end());

    priority_queue<int, vector<int>, greater<int>> pq;
    for(auto it: v) {
        pq.push(it.second);
        while(pq.size() > it.first) {
            pq.pop();
        }
    }

    while(pq.size()) {
        ret += pq.top(); pq.pop();
    }

    cout << ret << '\n';
    return 0;
}