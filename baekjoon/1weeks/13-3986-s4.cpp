// https://www.acmicpc.net/problem/3986

#include <bits/stdc++.h>
using namespace std;

/*
	날짜: 2025-08-06
	횟수: 3
*/
int n, ret;
string s;
stack<char> stk;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i=0; i<n; i++) {
        while(!stk.empty()) stk.pop();

        cin >> s;
        s.c_str();

        for (char it: s) {
            if (stk.empty()) {
                stk.push(it);
            } else if (stk.top() == it) {
                stk.pop();
            } else {
                stk.push(it);
            }
        }

        if (stk.size() == 0) {
            ret++;
        }
    }

    cout << ret << "\n";

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// int n, ret;
// string s;
// int main() {
//   ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

//   cin >> n;
  
//   for (int i=0; i<n; i++) {
//     cin >> s;

//     stack<char> stk;
//     for (char c: s) {
//       if(stk.size() && stk.top() == c) stk.pop();
//       else stk.push(c);
//     }

//     if (stk.size() == 0) ret++;
//   }

//   cout << ret << "\n";

//   return 0;
// }

/*
	날짜: 2023-08-08
	횟수: 2
  특이사항: stack<T> 자료구조를 제공한다...
*/
// int N, ret;
// int main() {
//     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//     cin >> N;

//     for (int i=0; i<N; i++) {
//         string I; // 2 < I.size() < 100,000
//         cin >> I; 
//         vector<char> stk;
//         for (int j=0; j<I.size(); j++) {
//             if (stk.size() == 0) stk.push_back(I[j]);
//             else {
//                 if (stk.back() == I[j]) stk.pop_back();
//                 else stk.push_back(I[j]);
//             }
//             // if (stk.size() >= 3) break;
//             if (j == I.size()-1 && stk.size() == 0) ret++;
//         }
//     }

//     cout << ret << "\n";

//     return 0;
// }