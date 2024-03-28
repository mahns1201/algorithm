#include <bits/stdc++.h>
using namespace std;

/*
	날짜: 2024-03-29
	횟수: 1
*/

int n, t;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    priority_queue<int> pq;
    for(int i=0; i<n; i++) {
        cin >> t;
        if(t==0) {
            if(pq.empty()) {
                cout << 0 << '\n';
            } else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        } else {
            pq.push(t);
        }
    }

    return 0;
}