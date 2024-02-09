#include <bits/stdc++.h>
using namespace std;

/*
	날짜: 2024-02-10
	횟수: 1
    메모: 이진 탐색 응용
*/

int n, m, max_h;
int trees[1000004];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    
    for(int i = 0; i < n; i++) cin >> trees[i];
    sort(trees, trees + n);
    
    long long low = 0;
    long long high = trees[n - 1];

    while (low <= high) {
        long long _sum = 0;
        long long cut = (low + high) / 2;

        for(int i=0; i<n; i++) {
            if (trees[i] - cut > 0) _sum += trees[i] - cut;
        }

        if(_sum >= m) { 
            max_h = cut;
            low = cut + 1;
        } else {
            high = cut - 1;
        }
    }
    
    cout << max_h << "\n";
}