#include <bits/stdc++.h>
using namespace std;

/*
	날짜: 2024-02-07
	횟수: 1
    메모: DP 간단한 문제부터 연습하자
*/

int n;
vector<int> v;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    
    v.push_back(0);
    v.push_back(0);
    v.push_back(1);
    v.push_back(1);

    if (n == 1) {
        cout << 0 << "\n";
        exit(0); 
    }

    if (n == 2 || n == 3) {
        cout << 1 << "\n";
        exit(0); 
    }

    for (int i=4; i<n+1; i++) {
        int t = 987654321;
        int t3 =0, t2 =0, t1 =0;
        if (i%3 == 0) {
            t3 = v[i/3];
            t = min(t, t3);
        } 
        if (i%2 == 0) {
            t2 = v[i/2];
            t = min(t, t2);
        }
        t1 = v[i-1];
        t = min(t, t1);

        // cout << t3 << " " << t2 << " " << t1 << "\n";
        // cout << i << " " << t << "\n\n";
        v.push_back(1+t);
    }

    cout << v[n] << "\n";

    return 0;
}