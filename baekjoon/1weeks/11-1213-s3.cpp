// https://www.acmicpc.net/problem/1213
// 팰린드롬

/*
    날짜: 2025-08-06
	횟수: 3
    특이사항: 잘풀었다! string에 c_str로 char*로 만든 후 stk으로 해결.
*/
#include <bits/stdc++.h>
using namespace std;

stack<char> stk;
string s, ret, delimeter;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s;
    sort(s.begin(), s.end());

    for (char it: s) {
        // 빈 stk이면 항상 넣는다.
        if (stk.empty()) {
            stk.push(it);

        // stk의 최상단과 넣는 값이 같으면 pop한다. 그리고 ret에 더해준다.
        } else if (stk.top() == it) {
            ret += it;
            stk.pop();
        } else {
            stk.push(it);
        }
    }

    if (stk.size() > 1) {
        cout << "I'm Sorry Hansoo\n";
    } else {
        string reverse_ret = ret;
        reverse(reverse_ret.begin(), reverse_ret.end());
        if (!stk.empty()) ret += stk.top();
        ret += reverse_ret;
        cout << ret << "\n";
    }

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// string s, a;
// map<char, int> cnt; // cnt array로도 풀어보자
// int main() {
//   ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//   cin >> s;

//   for (char c: s) {
//     cnt[c]++;
//   }

//   char mid;
//   int odd = 0;
//   for (char i='Z'; i>='A'; i--) {
//     if (cnt[i]) {
//       if (cnt[i] & 1) {
//         mid = i;
//         cnt[i]--;
//         odd += 1;
//       }
//       if (odd == 2) {
//         break; 
//       }

//       for(int j=cnt[i]; j>0; j-=2) {
//         a = i + a + i;
//       }
//     }
//   }
  
//   if (mid) {
//     a.insert(a.begin() + a.size()/2, mid);
//   } 

//   if (odd == 2) {
//     cout << "I'm Sorry Hansoo" << "\n";
//   } else {
//     cout << a << "\n";
//   }

//   return 0;
// }


// 순열로 풀려다가 틀림;

// string r_s, o_s;
// int main() {
//   ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

//   cin >> r_s;
//   o_s = r_s;
//   reverse(r_s.begin(), r_s.end());

//   do {
//     if (o_s == r_s) {
//       cout << o_s << "\n";
//       return 0;
//     }
//   } while (next_permutation(o_s.begin(), o_s.end()));

//   cout << "I'm Sorry Hansoo" << "\n";

//   return 0;
// }

/*
	날짜: 2023-08-07
	횟수: 2
    특이사항: 반복문 돌리는 것에 대해 다시 확인...
*/
// string I;
// int arr[200];
// int main() {
//     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//     cin >> I;
//     for (char i: I) {
//         arr[(int) i]++;
//     }

//     int odd = 0;
//     string ret = "";
//     string mid = "";

//     for (int i=199; i>0; i--) {
//         if (arr[i] & 1) {
//             mid = (char) i;
//             odd++;
//         } 
//         if (odd > 1) {
//             cout << "I'm Sorry Hansoo" << "\n";
//             exit(0);
//         }
//     }
    
//     for (int i=91; i>=65; i--) {
//         while(arr[i] >= 2) {
//             ret = (char) i + ret;
//             ret += (char) i; 
//             arr[i] -= 2;
//         }
//     }

//     if (mid.size() > 0) {
//         ret.insert(ret.length()/2, mid);
//     }
    
//     cout << ret << "\n";

//     return 0;
// }