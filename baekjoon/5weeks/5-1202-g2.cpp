#include <bits/stdc++.h>
using namespace std;

/*
    날짜: 2024-04-03
	횟수: 1
    메모: 다시 풀어보기 / 반복문을 초기화 없이 실행할 땐 while을 쓰자.
*/

long long result;
int n, k, w, p, c;
vector<pair<int, int>> jewels;
vector<int> bags;

// bool cmp(pair<int, int> a, pair<int, int> b) {
//     if (a.first==b.first) {
//         return a.second < b.second;
//     }

//     return a.first < b.first;
// }

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    
    for(int i=0; i<n; i++) {
        cin >> w >> p;
        jewels.push_back({w, p});
    }

    for(int i=0; i<k; i++) {
        cin >> c;
        bags.push_back(c);
    }

    sort(jewels.begin(), jewels.end());
    sort(bags.begin(), bags.end());

    priority_queue<int> pq;

    // j.first: 무게
    // j.second: 가격
    int j=0;
    for(int bag: bags) {
        while(j<n) {
            if(bag>=jewels[j].first) {
                pq.push(jewels[j].second);
            } else break;
        }

        if(pq.size()) {
            result += pq.top();
            pq.pop();
        }
    }

    cout << result << '\n';

    // for(auto it: jewels) {
    //     cout << it.first << ' ' << it.second << '\n';
    // }

    // for(auto it: bags) {
    //     cout << it << ' ';
    // }
    // cout << '\n';

    return 0;
}