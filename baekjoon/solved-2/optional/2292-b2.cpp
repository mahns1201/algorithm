// https://www.acmicpc.net/problem/2292

#include <bits/stdc++.h>
using namespace std;

int N;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    int t=1;
    for (int i=0; i<N; i++) {
        t += 6*i;
        if (t >= N) {
            cout << i+1 << "\n";
            break;
        }
    }

    return 0; 
}