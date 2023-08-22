// https://www.acmicpc.net/problem/9012

#include <bits/stdc++.h>
using namespace std;

int TRY;
stack<char> stk;
int pu = 0;
int po = 0;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> TRY;

    while (TRY>0) {
        TRY--;
        while(!stk.empty()) stk.pop();
        string S;
        cin >> S;

        if (S.size() & 1) {
            cout << "NO" << "\n";
            continue;
        }

        
        for (int i=0; i<S.size(); i++) {
            char s = S[i];

            if (!stk.size()) {
                if (s == '(') {
                    stk.push(s);
                } else {
                    stk.push(s);
                    break;
                }
            } else {
                if (s == '(') {
                    stk.push(s);
                } else {
                    stk.pop();
                }
            }
        }

        if (!stk.size()) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }

    return 0;
}