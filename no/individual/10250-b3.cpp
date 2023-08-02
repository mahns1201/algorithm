// https://www.acmicpc.net/problem/10250

#include <bits/stdc++.h>
using namespace std;

int H, W, N;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int x;
    cin >> x;
    string ret[x];

    for (int i=0; i<x; i++) {
        cin >> H >> W >> N;
        int h, w;
        
        h = N % H;
        w = N / H + 1;
        if (N % H == 0) {
            h = H;
            w = N / H;
        }

        string room;
        if (to_string(w).length() == 1) room = to_string(h) + "0" + to_string(w);
        else room = to_string(h) + to_string(w);

        ret[i] = room;
    }
    
    for (int j=0; j<x; j++) {
        cout << ret[j] << "\n";
    }

    return 0;
}