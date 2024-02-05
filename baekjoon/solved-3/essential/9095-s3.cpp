#include <bits/stdc++.h>
using namespace std;


/*
	날짜: 2024-02-05
	횟수: 1
*/

int n, t, result;

void go(int val) {
    if (val < 0) {
        return;
    }

    if (val == 0) {
        result++;
        return;
    }

    go(val - 1);
    go(val - 2);
    go(val - 3);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;

    while (n > 0) {
        n--;
        cin >> t;
        result = 0;
        go(t);
        cout << result << "\n";
    }

    return 0;
}