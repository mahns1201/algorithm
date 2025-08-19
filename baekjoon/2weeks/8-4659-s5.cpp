// https://www.acmicpc.net/problem/4659

#include <bits/stdc++.h>
using namespace std;

/*
	날짜: 2025-08-18
	횟수: 2
    메모: 다시 풀어보자
*/

string s;
char mo[5] = { 'a', 'e', 'i', 'o', 'u' };

bool isMo(char m) {
    for (char it: mo) if (it == m) return true;

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while(cin >> s) {
        int mo_cnt = 0;
        int ja_cnt = 0;
        bool is_mo = false;

        if (s == "end") break;
        
        char prev = '0';
        for (char it: s) {
            if (prev != 'e' && prev != 'o' && prev == it || mo_cnt >= 3 || ja_cnt >= 3) {
                is_mo = false;
                break;
            }

            if (isMo(it)) {
                mo_cnt++;
                ja_cnt = 0;
                is_mo = true;
            } else {
                mo_cnt = 0;
                ja_cnt++;
            }

            prev = it;
        }

        if (mo_cnt < 3 && ja_cnt < 3 && is_mo) cout << "<" << s << "> is acceptable.\n"; 
        else cout << "<" << s << "> is not acceptable.\n"; 
    }

    return 0;
}

/*
	횟수: 1
    메모: 너무 비효율적인 방법이다.
*/

// char mo[] = {'a', 'e', 'i', 'o', 'u'};
// stack<char> stk;
// stack<char> stkMo;

// bool isMo(char c) {
//     for (char m: mo) {
//         if (m == c) return true;
//     }
//     return false;
// }

// bool noMo(string S) {
//     int t=0;
//     for (char m: mo) {
//         if (S.find(m) != string::npos) {
//             t++;
//             break;
//         } 
//     }
//     if (t == 0) {
//         return true;
//     }

//     return false; 
// }

// bool isTriple(string S) {
//     int moCnt = 0;
//     int jaCnt = 0;
        
//     for (char s: S) {
//         // cout << moCnt << " " << jaCnt << " " << s << "\n";
//         if (moCnt >= 3 || jaCnt >= 3) return true;

//         if (stkMo.empty()) {
//             if (isMo(s)) moCnt++;
//             else jaCnt++;
//             stkMo.push(s);
//             continue;
//         }

//         if (moCnt != 0) {
//             if (isMo(s)) {
//                 moCnt++;
//                 continue;  
//             }
//             else {
//                 while(!stkMo.empty()) stkMo.pop();
//                 stkMo.push(s);
//                 moCnt = 0;
//                 jaCnt++;
//                 continue; 
//             }
//         } 
        
//         if (jaCnt != 0){
//             if (!isMo(s)) {
//                 jaCnt++;
//                 continue;
//             } 
//             else {
//                 while(!stkMo.empty()) stkMo.pop();
//                 stkMo.push(s);
//                 jaCnt = 0;
//                 moCnt++; 
//                 continue;  
//             }
//         }
//     }

//     if (moCnt >= 3 || jaCnt >= 3) return true;
//     return false;
// }

// bool isSequence(string S) {
//     if (S.size() == 1) return false; 

//     for (char s: S) {
//         // cout << stk.size() << "\n";
        
//         if (stk.empty()) {
//             stk.push(s);
//             continue;
//         } 

//         if (stk.size() == 1) {
//             if (s == 'e' || s == 'o') {
//                 if (stk.top() == s) {
//                     stk.push(s);
//                     continue;
//                 } else {
//                     while(!stk.empty()) stk.pop();
//                     stk.push(s);
//                     continue;
//                 }
//             } else {
//                 if (stk.top() == s) {
//                     return true;
//                 } else {
//                     while(!stk.empty()) stk.pop();
//                     stk.push(s);
//                     continue;
//                 }
//             }
//         }

//         if (stk.size() == 2) {
//             if (s == 'e' || s == 'o') {
//                 if (stk.top() == s) {
//                     // cout << "!!" << "\n";
//                     return true;
//                 } else {
//                     while(!stk.empty()) stk.pop();
//                     stk.push(s);
//                     continue;
//                 }
//             } else {
//                 while(!stk.empty()) stk.pop();
//                 stk.push(s);
//                 continue;
//             }
//         }
//     }

//     return false;
// }

// int main() {
//     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

//     while (true) {
//         string S;
//         cin >> S;
//         if (S == "end") break;
//         while(!stkMo.empty()) stkMo.pop();
//         while(!stk.empty()) stk.pop();
//         if (noMo(S) || isTriple(S) || isSequence(S)) {
//             cout << "<" << S << "> is not acceptable." << "\n";
//         } else {
//             cout << "<" << S << "> is acceptable." << "\n";
//         }
//     }
    
//     return 0;
// }