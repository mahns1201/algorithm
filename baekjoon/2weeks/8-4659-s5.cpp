// https://www.acmicpc.net/problem/4659

#include <bits/stdc++.h>
using namespace std;

char mo[] = {'a', 'e', 'i', 'o', 'u'};
stack<char> stk;
stack<char> stkMo;

bool isMo(char c) {
    for (char m: mo) {
        if (m == c) return true;
    }
    return false;
}

bool noMo(string S) {
    int t=0;
    for (char m: mo) {
        if (S.find(m) != string::npos) {
            t++;
            break;
        } 
    }
    if (t == 0) {
        return true;
    }

    return false; 
}

bool isTriple(string S) {
    int moCnt = 0;
    int jaCnt = 0;
        
    for (char s: S) {
        // cout << moCnt << " " << jaCnt << " " << s << "\n";
        if (moCnt >= 3 || jaCnt >= 3) return true;

        if (stkMo.empty()) {
            if (isMo(s)) moCnt++;
            else jaCnt++;
            stkMo.push(s);
            continue;
        }

        if (moCnt != 0) {
            if (isMo(s)) {
                moCnt++;
                continue;  
            }
            else {
                while(!stkMo.empty()) stkMo.pop();
                stkMo.push(s);
                moCnt = 0;
                jaCnt++;
                continue; 
            }
        } 
        
        if (jaCnt != 0){
            if (!isMo(s)) {
                jaCnt++;
                continue;
            } 
            else {
                while(!stkMo.empty()) stkMo.pop();
                stkMo.push(s);
                jaCnt = 0;
                moCnt++; 
                continue;  
            }
        }
    }

    if (moCnt >= 3 || jaCnt >= 3) return true;
    return false;
}

bool isSequence(string S) {
    if (S.size() == 1) return false; 

    for (char s: S) {
        // cout << stk.size() << "\n";
        
        if (stk.empty()) {
            stk.push(s);
            continue;
        } 

        if (stk.size() == 1) {
            if (s == 'e' || s == 'o') {
                if (stk.top() == s) {
                    stk.push(s);
                    continue;
                } else {
                    while(!stk.empty()) stk.pop();
                    stk.push(s);
                    continue;
                }
            } else {
                if (stk.top() == s) {
                    return true;
                } else {
                    while(!stk.empty()) stk.pop();
                    stk.push(s);
                    continue;
                }
            }
        }

        if (stk.size() == 2) {
            if (s == 'e' || s == 'o') {
                if (stk.top() == s) {
                    // cout << "!!" << "\n";
                    return true;
                } else {
                    while(!stk.empty()) stk.pop();
                    stk.push(s);
                    continue;
                }
            } else {
                while(!stk.empty()) stk.pop();
                stk.push(s);
                continue;
            }
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    while (true) {
        string S;
        cin >> S;
        if (S == "end") break;
        while(!stkMo.empty()) stkMo.pop();
        while(!stk.empty()) stk.pop();
        if (noMo(S) || isTriple(S) || isSequence(S)) {
            cout << "<" << S << "> is not acceptable." << "\n";
        } else {
            cout << "<" << S << "> is acceptable." << "\n";
        }
    }
    
    return 0;
}