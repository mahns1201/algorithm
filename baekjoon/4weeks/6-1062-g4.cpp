#include <bits/stdc++.h>
using namespace std;

/*
    날짜: 2024-03-14
	횟수: 1
    메모: 이게 왜 골드4지... 진짜 너무 어려운데?
*/

string s;
int n, k, result;
int alpha[26];
// a c i n t 필수 포함
// 0 2 8 13 19
vector<int> words;

void go(int try_cnt, int start, int teach_word) {
    // cout << try_cnt << ' ' << start << ' ' << teach_word << '\n';
    if(try_cnt == 0) {
        int ret = 0;
        for(int word: words) {
            if((teach_word & word) == word) {
                ret++;
            }
        }
        result = max(result, ret);
        return;
    }

    for(int i=start; i<26; i++) {
        if((teach_word & (1<<i)) == 0) {
            teach_word |= (1<<i);
            go(try_cnt-1, i, teach_word);
            teach_word &= ~(1<<i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> s;
        int word = 0;
        for(int j=0; j<s.size(); j++){
            word |= (1 << (s[j]-'a'));
        }
        words.push_back(word);
    }

    int teach_word = 0;
    teach_word |= (1<<('a'-97));
    teach_word |= (1<<('c'-97));
    teach_word |= (1<<('i'-97));
    teach_word |= (1<<('n'-97));
    teach_word |= (1<<('t'-97));

    go(k-5, 0, teach_word);

    cout << result << '\n';

    return 0;
}