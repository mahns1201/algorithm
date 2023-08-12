// https://www.acmicpc.net/problem/2775

#include <bits/stdc++.h>
using namespace std;

int NUM;

int go (int k, int n) {
    int ret = 0;
    if (n == 1) return 1;
    if (k == 0) return n;

    for (int i=1; i<n+1; i++) {
        ret += go(k-1, i);
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> NUM;
    while (0 < NUM) {
        NUM--;
        
        int K, N, ret;
        cin >> K >> N;

        ret = go(K, N);
        cout << ret << "\n";
    }
    
    return 0;
}