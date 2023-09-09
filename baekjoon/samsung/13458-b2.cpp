// https://www.acmicpc.net/problem/13458

#include <bits/stdc++.h>
using namespace std;

int room, t, n, m;
long long ret;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> room;
    int people[room];
    for (int i=0; i<room; i++) {
        cin >> people[i];
    }

    cin >> n >> m;

    for (int i=0; i<room; i++) {
        double temp = people[i];
        if (temp <= n) ret ++;
        else {
            temp -= n;
            // // ceil(temp / m);
            // cout << temp / m << " " << ceil(temp / m) << "\n";
            ret ++;
            ret += ceil(temp / m);
        }
    }

    cout << ret << "\n";

    return 0;
}