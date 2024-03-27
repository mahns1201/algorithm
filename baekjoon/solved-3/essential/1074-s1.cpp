#include <bits/stdc++.h>
using namespace std;

/*
	날짜: 2024-03-28
	횟수: 1
*/

int n, r, c, ret;
// y: row, x: col

void divide_qonquer(int y, int x, int d) {
    cout << y << ' ' << x << ' ' << d << '\n';
    if(y==r && x==c) return;
    // if(d==0) return;

    if(y<=r && r<y+d && x<=c && c<x+d) {
        cout << '1' << '\n';
        divide_qonquer(y, x, d/2);
    } else if(y<=r && r<y+d && x+d<=c && c<x+d*2) {
        ret += d*d;
        cout << '2' << '\n';
        divide_qonquer(y, x+d, d/2);
    } else if(y+d<=r && r<y+d*2 && x<=c && c<x+d) {
        ret += 2*d*d;
        cout << '3' << '\n';
        divide_qonquer(y+d, x, d/2);
    } else {
        ret += 3*d*d;
        cout << '4' << '\n';
        divide_qonquer(y+d, x+d, d/2);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> r >> c;

    divide_qonquer(0, 0, pow(2, n)/2);
    cout << ret << '\n';

    return 0;
}
