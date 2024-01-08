// https://www.acmicpc.net/problem/10866

#include <bits/stdc++.h>
using namespace std;

/*
	날짜: 2024-01-09
	횟수: 1
*/

int n, m;
deque<int> dq;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;

    for (int i=0; i<n; i++) {
        string s;
        cin >> s;

        if (s == "push_front") {
            cin >> m;
            dq.push_front(m);
        } else if (s == "push_back") {
            cin >> m;
            dq.push_back(m);
        } else if (s == "pop_front") {
            if (!dq.size()) {
                cout << -1 << "\n";
            } else {
                cout << dq.front() << "\n";
                dq.pop_front();
            }
        } else if (s == "pop_back") {
            if (!dq.size()) {
                cout << -1 << "\n";
            } else {
                cout << dq.back() << "\n";
                dq.pop_back();
            }
        } else if (s == "size") {
            cout << dq.size() << "\n";
        } else if (s == "empty") {
            if (dq.size()) {
                cout << 0 << "\n";
            } else {
                cout << 1 << "\n";
            }
        } else if (s == "front") {
            if (!dq.size()) {
                cout << -1 << "\n";
            } else {
                cout << dq.front() << "\n";
            }
        } else if (s == "back") {
            if (!dq.size()) {
                cout << -1 << "\n";
            } else {
                cout << dq.back() << "\n";
            }
        }   
    }
    
    return 0;
}