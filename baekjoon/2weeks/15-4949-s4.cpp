// https://www.acmicpc.net/problem/4949

/*
    날짜: 2023-09-08
	횟수: 1
    메모: 나쁘지 않았다... 1트
*/
#include <bits/stdc++.h>
using namespace std;

string input;
stack<char> stk;
vector<string> ret;

string is_bracket(char i) {
    if (i == '(' || i == '[' ) {
        return "left";
    }
    else if (i == ')' || i == ']') {
        return "right";
    }
    else return "none";
}

bool is_match(char left, char right) {
    // cout << "left: " << left << " " << "right: " << right << "\n";
    if (left == '(' && right == ')') return true;
    else if (left == '[' && right == ']') return true;
    else return false;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    while(true) {
        getline(cin, input);
        if (input == ".") break;
        while(!stk.empty()) stk.pop();

        for (int j=0; j<input.size(); j++) {
            char i = input[j];

            if (is_bracket(i) == "left") {
                stk.push(i);
                continue;
            } 
            
            else if (is_bracket(i) == "right") {
                if (!stk.size()) {
                    ret.push_back("no");
                    break;
                } else {
                    if (is_match(stk.top(), i)) {
                        stk.pop();
                        continue;
                    } else {
                        ret.push_back("no");
                        break;
                    }
                }
            }

            if (j == input.size()-1) {
                if (stk.size()) ret.push_back("no");
                else ret.push_back("yes");
            } 
        }
    }

    for (auto result: ret) {
        cout << result << "\n";
    }

    return 0;
}