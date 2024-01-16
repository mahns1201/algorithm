// https://www.acmicpc.net/problem/2231

#include <bits/stdc++.h>
using namespace std;


/*
	날짜: 2023-08-07
	횟수: 1
*/
int N;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    
    for (int i=1; i<N+1; i++) {
        int ret = 0;
        ret += i;
        string si = to_string(i);
        for (char s: si) ret += s - '0';
        if (N == ret) {
            cout << i << "\n";
            exit(0);
        } 
    }

    cout << "0" << "\n";

    return 0;
}