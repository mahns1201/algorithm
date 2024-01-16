// https://www.acmicpc.net/problem/10845

#include <bits/stdc++.h>
using namespace std;

/*
	날짜: 2024-01-04
	횟수: 1
*/

int n, m;
queue<int> q;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;

    for (int i=0; i<n; i++) {
        string s;
        cin >> s;

        if (s == "push") {
            cin >> m;
            q.push(m);
        } else if (s == "pop") {
            if (!q.size()) {
                cout << -1 << "\n";
            } else {
                cout << q.front() << "\n";
                q.pop();
            }
        } else if (s == "front") {
            if (!q.size()) {
                cout << -1 << "\n";
            } else {
                cout << q.front() << "\n";
            }
        } else if (s == "back") {
            if (!q.size()) {
                cout << -1 << "\n";
            } else {
                cout << q.back() << "\n";
            }
        } else if (s == "size") {
            cout << q.size() << "\n";
        }  else if (s == "empty") {
            if (q.size()) {
                cout << 0 << "\n";
            } else {
                cout << 1 << "\n";
            }
        }
    }
    
    return 0;
}