#include <bits/stdc++.h>
using namespace std;

/*
	날짜: 2024-01-19
	횟수: 1
    특이사항: 진짜 잘 풀었다 !!
*/

int n, ret;
int two_cnt;
int five_cnt;
void calc(int x) {
    int t=x;
    for (int i=2; i<=x; i++) {
        // cout << i << "\n";
        while(true) {
            if (t%i != 0) break;
            // cout << i << " | " << "t: " << t / i << "\n";
            if (i == 2) two_cnt++;
            else if (i == 5) five_cnt++;
            t /= i;
        }
        if (t == 1) return;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;

    // if (n <= 4) {
    //     cout << 0;
    //     exit(0);
    // }
    
    for (int i=2; i<=n; i++) {
        calc(i);
    }

    ret = min(two_cnt, five_cnt);
    cout << ret << "\n";

    return 0;
}