// https://www.acmicpc.net/problem/2828

#include <bits/stdc++.h>
using namespace std;

int N, M, L, T;
int curr = 1;
int ret;

void go(int target) {
    // 가만히 있어도 되는 상황
    if (curr == target) {
        return;
    }

    // 오른쪽으로 가야하는 상황
    else if (curr < target) {
        // 바구니가 target을 포함하는 상황
        if (target <= curr + M - 1) {
            return;
        }
        ret += target + 1 - curr - M;
        curr += (target + 1 - curr - M);
        return;
    }

    // 왼쪽으로 가야하는 상황
    else if (target < curr) {
        ret += curr - target;
        // curr -= (curr - target);
        curr = target;
        return;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> L;

    // L 만큼 반복
    // current = 1, length = M, target = cin >> T
    for (int i=0; i<L; i++) {
        int T;
        cin >> T;
        go(T);
    }

    cout << ret << "\n";

    return 0;
}