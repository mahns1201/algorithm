#include <bits/stdc++.h>
using namespace std;

/*
	날짜: 2024-02-04
	횟수: 1
*/

const int max_x = 24;
int n, x;
string oper;
int arr[max_x];

void cal(string oper, int x) {
    if (oper == "add") {
        arr[x] = 1;
    } else if (oper == "remove") {
        arr[x] = 0;
    } else if (oper == "check") {
        arr[x] ? cout << 1 << "\n" : cout << 0 << "\n";
    } else if (oper == "toggle") {
        arr[x] ? arr[x] = 0 : arr[x] = 1;
    } else if (oper == "all") {
        for (int i=1; i<=20; i++) arr[i] = 1;
    } else if (oper == "empty") {
        for (int i=1; i<=20; i++) arr[i] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> oper;
        if (oper == "all" || oper == "empty") {
            cal(oper, 0);
        } else {
            cin >> x;
            cal(oper, x);
        }
    }

    return 0;
}