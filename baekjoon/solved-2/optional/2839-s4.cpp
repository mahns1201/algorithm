// https://www.acmicpc.net/problem/2839

#include <bits/stdc++.h>
using namespace std;

int N;
int ret = 1667;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    
    int maxV = N/3 + 1;
    for (int i=0; i<maxV; i++) {
        for (int j=0; j<maxV; j++) {
            if (5*i + 3*j == N) {
                if (i+j < ret) ret = i + j;
            }
        }
    }

    if (ret == 1667) {
        cout << -1 << "\n";
        exit(0);
    }
    cout << ret << "\n";

    return 0;
}