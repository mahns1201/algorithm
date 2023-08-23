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

/*
    날짜: 2023-08-23
	횟수: 2
    특이사항: 더 잘 푼 듯.
*/
// int N, M, TRY, ret;
// pair<int, int> b;
// int main() {
//     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//     cin >> N >> M >> TRY;

//     b = {1, M}; // basket init

//     while (TRY>0) {
//         TRY--;
//         int tn, bf, bs;
//         cin >> tn;
        
//         bf = b.first;
//         bs = b.second;

//         // cout << bf << " " << bs << "\n";

//         if (bf <= tn && tn <= bs) {
//             continue;
//         } else if (tn < bf) {
//             // 왼쪽으로 가야하는 상황
//             // 몇 칸 가야하나? bf - tn
//             ret += bf - tn;
//             b.first = bf - (bf - tn);
//             b.second = bs - (bf - tn);
//             if (b.first < 1) b.second = 1;
//         } else if (bs < tn) {
//             // 오른쪽으로 가야하는 상황
//             // 몇 칸 가야하나? tn - bs
//             ret += tn - bs;
//             b.first = bf + (tn - bs);
//             b.second = bs + (tn - bs);
//             if (b.second > N) b.second = N;
//         } 
//         // else {
//         //     cout << "debug\n";
//         // }
//     }
    
//     cout << ret << "\n";
    

//     return 0;
// }