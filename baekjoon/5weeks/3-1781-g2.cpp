#include <bits/stdc++.h>
using namespace std;

/*
    날짜: 2024-03-31
	횟수: 1
*/

int n, a, b, ret;
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> pq;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a >> b;
        v.push_back({a, b});
    }

    sort(v.begin(), v.end());
    
    // cout << "\n\n";
    for(auto it: v) {
        // cout << it.first << ' ' << it.second << '\n';
        pq.push(it.second);
        while(pq.size() > it.first) pq.pop();
    }

    while(pq.size()) {
        ret += pq.top();
        pq.pop();
    }
    cout << ret << '\n';
    return 0;
}