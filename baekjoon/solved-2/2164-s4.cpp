// https://www.acmicpc.net/problem/2164

#include <bits/stdc++.h>
using namespace std;

/*
	날짜: 2024-01-03
	횟수: 1
*/

int n;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;

    if (n == 1) {
        cout << 1 << "\n";
        exit(0);
    }
    
    deque<int> dq;

    for (int i=n; i>0; i--) {
        dq.push_back(i);
    }

    // cout << dq.front() << " " << dq.back() << "\n\n\n";

    while (dq.size()) {
        dq.pop_back();

        if (dq.size() == 1) {
            cout << dq.front() << "\n";
            exit(0);
        }

        dq.push_front(dq.back());
        dq.pop_back();

        if (dq.size() == 1) {
            cout << dq.front() << "\n";
            exit(0);
        }
    }

    return 0;
}