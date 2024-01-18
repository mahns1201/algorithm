#include <bits/stdc++.h>
using namespace std;

/*
	날짜: 2024-01-19
	횟수: 1
*/

int n, x, ret;
stack<int> stk;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    
    for (int i=0; i<n; i++) {
        cin >> x;
        if (x == 0) {
            stk.pop();
        } else {
            stk.push(x);
        }
    }

    while(stk.size()) {
        ret += stk.top();
        stk.pop();
    }

    cout << ret << "\n";

    return 0;
}