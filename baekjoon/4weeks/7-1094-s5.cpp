#include <bits/stdc++.h>
using namespace std;

/*
    날짜: 2024-03-17
	횟수: 1
*/

int n, ret;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;

    while(n>0) {
        int k;
        for(k=0; k<7; k++) {
            if(pow(2, k+1) > n) {
                n -= pow(2, k);
                ret++;
                break;
            }
        }
    }
    cout << ret << '\n';

    return 0;
}