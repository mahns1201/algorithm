#include <bits/stdc++.h>
using namespace std;

/*
	날짜: 2024-04-01
	횟수: 1
*/

int n, r;
int arr[10];

void comb(int start, vector<int> v) {
    if (v.size() == r) {
        for(int it: v) cout << it+1 << ' ';
        cout << '\n';
        return;
    }

    for (int i=start+1; i<n; i++) {
        v.push_back(i);
        comb(i, v);
        v.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> r;
    // for(int i=1; i<n+1; i++) arr[i] = i;
    
    vector<int> v;
    comb(-1, v);

    return 0;
}