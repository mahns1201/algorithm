// https://www.acmicpc.net/problem/1436

#include <bits/stdc++.h>
using namespace std;

int N;
int cnt = 2;
int ret = 1666;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    if (N==1) {
        cout << 666 << "\n";
        exit(0);
    }

    if (N==2) {
        cout << 1666 << "\n";
        exit(0);
    }

    while (true) {
        ret++;
        string sRet = to_string(ret);
        
        for (int i=sRet.size(); i>2; i--) {
            if (sRet.substr(i-3, 3) == "666") {
                cnt++;
                break;
            } 
        }

        if (N == cnt) break;
    }

    cout << ret << "\n";
    
    return 0;
}