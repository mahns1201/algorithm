// https://www.acmicpc.net/problem/2910
// 빈도 정렬

/*
    날짜: 2025-08-18
	횟수: 2
*/
#include <bits/stdc++.h>
using namespace std;

int n, c, t;
map<int, int> mp_cnt;
map<int, int> mp_order;
vector<pair<int, int>> ret;

bool cmp(pair<int, int> f, pair<int, int> s) {
    if (f.second == s.second) {
        return mp_order[f.first] < mp_order[s.first];
    }

    return f.second > s.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> c;

    for (int i=0; i<n; i++) {
        cin >> t;
        mp_cnt[t]++;
        if (!mp_order[t]) {
            mp_order[t] = i+1;
        }
    }
    
    for (auto &p: mp_cnt) {
        ret.push_back({ p.first, p.second });
    }
    
    sort(ret.begin(), ret.end(), cmp);

    for (auto it: ret) {
        for (int i=0; i<it.second; i++) {
            cout << it.first << " ";
        }
    }
    cout << "\n";

    return 0;
}

// int n, c;
// int a[1004];
// map<int, int> m_cnt, m_order;
// vector<pair<int, int>> ret;

// bool cmp(pair<int, int> a, pair<int, int> b) {
//     if (a.second == b.second) {
//         return m_order[a.first] < m_order[b.first];
//     }
//     return a.second > b.second;
// }

// int main() {
//     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//     cin >> n >> c;

//     for (int i=0; i<n; i++) {
//         cin >> a[i];
//         m_cnt[a[i]]++;
//         if (m_order[a[i]] == 0) m_order[a[i]] = i+1;
//     }

//     for (auto it: m_cnt) ret.push_back({it.first, it.second}); // key, 

//     sort(ret.begin(), ret.end(), cmp);

//     for (auto r: ret) {
//         for (int j=0; j<r.second; j++) {
//             cout << r.first << " ";
//         }
//     }
//     cout << "\n";
    
//     return 0;
// }