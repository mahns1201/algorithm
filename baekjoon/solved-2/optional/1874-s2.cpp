#include <bits/stdc++.h>
using namespace std;

/*
	날짜: 2024-02-01
	횟수: 1
    특이사항: 진짜 개억지로 풀었다; 다시 풀자.
*/

int n, cursor;
stack<int> stk;
vector<string> ret;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    int arr[n];
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    for (int i=1; i<=n; i++) {
        if (i < arr[cursor]) {
            stk.push(i);
            ret.push_back("+");
            continue;
        } else if (i == arr[cursor]) {
            ret.push_back("+");
            ret.push_back("-");
            cursor++;
        } else {
            while(true) {
                if (!stk.top()) {
                    cout << "NO\n";
                    exit(0);
                }
                int t = stk.top(); stk.pop();
                int tt = arr[cursor];
                ret.push_back("-");
                cursor++;
                if (t == tt) {
                    i--;
                    break;
                } else {
                    cout << "NO\n";
                    exit(0);
                }
                
            }
        }
    }

    while(cursor < n) {
        while(true) {
            if (!stk.top()) {
                cout << "NO\n";
                exit(0);
            }
            int t = stk.top(); stk.pop();
            int tt = arr[cursor];
            ret.push_back("-");
            cursor ++;
            if (t == tt) {
                break;
            } else {
                cout << "NO\n";
                exit(0);
            }
        }
    }

    for (auto i: ret) {
        cout << i << "\n";
    }

    return 0;
}