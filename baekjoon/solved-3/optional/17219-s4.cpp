#include <bits/stdc++.h>
using namespace std;

/*
	날짜: 2024-02-06
	횟수: 1
*/

int n, m;
string url, pw;
map<string, string> mp;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;

    for (int i=0; i<n; i++) {
        cin >> url >> pw;
        mp[url] = pw;
    }

    for (int i=0; i<m; i++) {
        cin >> url;
        cout << mp[url] << "\n";
    }
    
    return 0;
}