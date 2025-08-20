// https://www.acmicpc.net/problem/2870

#include <bits/stdc++.h>
using namespace std;

/*
    날짜: 2025-08-20
	횟수: 1
*/

int t;
string s;
vector<string> ret;

bool cmp(string a, string b) {
    if (a.size() == b.size()) return a < b;
    return a.size() < b.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while(t--) {
        cin >> s;
        string prev = "";
        
        for (int i=0; i<s.size(); i++) {
            if (48 <= s[i]+0 && s[i]+0 <= 57) {
                if (prev == "0") prev = "";
                prev += s[i];
                if (i != s.size()-1) continue;
            }

            if (prev.size()) ret.push_back(prev);
            prev = "";
        }
    }

    sort(ret.begin(), ret.end(), cmp);
    for (string it: ret) cout << it << "\n";

    return 0;
}

