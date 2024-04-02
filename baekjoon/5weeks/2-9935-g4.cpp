#include <bits/stdc++.h>
using namespace std;

/*
	날짜: 2024-04-03
	횟수: 1
    메모: 각기 다른 방법으로 다시 풀어보자.
*/

string s, boom, result;

void make_boom() {
    if(result.substr(result.size()-int(boom.size()), boom.size()) == boom) {
        result.erase(result.size()-int(boom.size()), boom.size());
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s >> boom;

    for(int i=0; i<s.size(); i++) {
        result += s[i];
        if(result.size()>=boom.size()) {
            make_boom();
        }
    }

    if(result.size()) cout << result << '\n';
    else cout << "FRULA\n";

    return 0;
}