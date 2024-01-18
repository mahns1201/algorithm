#include <bits/stdc++.h>
using namespace std;

/*
	날짜: 2024-01-19
	횟수: 1
    특이사항: 다시 풀어보자. 생각도 다시 해보자.
*/

int n, m;

void calc(int x) {
    for (int i=2; i*i<=x; i++) {
        if (x%i == 0) return;
    }
    cout << x << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;

    for (int i=n; i<=m; i++) { 
        if (i == 1) continue;
        calc(i);
    }
    
    return 0;
}