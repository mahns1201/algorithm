// https://www.acmicpc.net/problem/10828

#include <bits/stdc++.h>
using namespace std;

/*
	날짜: 2024-01-03
	횟수: 1
*/

int n, m;
stack<int> stk;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;

    for (int i=0; i<n; i++) {
        string s;
        cin >> s;

        if (s == "push") {
            cin >> m;
            stk.push(m);
        } else if (s == "pop") {
            if (!stk.size()) {
                cout << -1 << "\n";
            } else {
                cout << stk.top() << "\n";
                stk.pop();
            }
        } else if (s == "size") {
            cout << stk.size() << "\n";
        }  else if (s == "empty") {
            if (stk.size()) {
                cout << 0 << "\n";
            } else {
                cout << 1 << "\n";
            }
        }  else if (s == "top") {
            if (stk.size()) {
                cout << stk.top() << "\n";
            } else {
                cout << -1 << "\n";
            }
        }
    }
    
    return 0;
}