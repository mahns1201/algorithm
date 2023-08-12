// https://www.acmicpc.net/problem/2869

#include <bits/stdc++.h>
using namespace std;

int A, B, V, ret;

void check(int d) {
    if (V <= (A-B) * (d-1) + A) {
        ret = d;
        check(d-1);
    } 
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> A >> B >> V;

    if (V < A) {
        cout << 1 << "\n";
        exit(0);
    }

    int r = V % (A-B);
    ret = V / (A-B);

    if (r != 0) ret++;
    check(ret-1);
    cout << ret << "\n";

    return 0;
}