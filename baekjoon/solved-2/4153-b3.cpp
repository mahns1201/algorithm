// https://www.acmicpc.net/status?user_id=sky300z&problem_id=4153&from_mine=1

#include <bits/stdc++.h>
using namespace std;

int a, b, c;
vector<string> ret;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    while (true) {
        cin >> a >> b >> c;
        if (a == 0 && b == 0 && c == 0) break;

        if (a * a + b * b == c * c) ret.push_back("right");
        else if (a * a + c * c == b * b) ret.push_back("right");
        else if (b * b + c * c == a * a) ret.push_back("right");
        else ret.push_back("wrong");
    }

    for (auto r: ret) {
        cout << r << "\n";
    }

    return 0;
}