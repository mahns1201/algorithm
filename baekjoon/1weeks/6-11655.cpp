// https://www.acmicpc.net/problem/11655

#include <bits/stdc++.h>
using namespace std;

string input;
char words[104];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	getline(cin, input);
	for(int i=0; i<input.size(); i++) {
		words[i] = input[i];
	}

	// 굳이 char words[104]에 안 넣고 그냥 하면 됨.
	for(int j=0; j<input.size(); j++) {
		int i = int(words[j]);
		int v = i + 13;
		if(65 <= i && i <= 90) {
			if (v > 90) v = v - 26;
		} else if(97 <= i && i <= 122) {
			if (v > 122) v = v - 26;
		} else v = v - 13;

		cout << char(v) << "";
	}
	cout << "\n";

	return 0;
}

/*
	날짜: 2023-07-31
	횟수: 2
*/
// #include <bits/stdc++.h>
// using namespace std;

// int shift = 13;
// string I;
// int main() {
//     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
//     getline(cin, I);

//     for (char s: I) {
//         if (65 <= s && s <= 90) {
//             if (90 < s+shift) cout << char(s+shift-26) << "";
//             else cout << char(s+shift) << "";
//         } else if (97 <= s && s <= 122) {
//             if (122 < s+shift) cout << char(s+shift-26) << "";
//             else cout << char(s+shift) << "";
//         } else cout << s << "";
//     }

//     return 0;
// }

/*
	날짜: 2023-12-27
	횟수: 3
*/
// string s;
// int main() {
//     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//     // cout << char(90) << char(122);
//     // 1. 65 ~ 90 사이
//     // 2. 97 ~ 122 사이
//     // 1, 2면 13을 더한다. 각각의 상황에서 90, 122 < 결과면 65, 97을 뺀다
    
//     getline(cin, s);
//     // cin >> s; // 122 -> 135 -> 
    
//     for (int i=0; i<s.size(); i++) {
//         int oi = int(s[i]);
//         int ri = oi;

//         if (65 <= oi && oi <= 90) {
//             ri = oi + 13;
//             if (90 < ri) ri = 65 + (ri - 91);
//         }

//         else if (97 <= oi && oi <= 122) {
//             ri = oi + 13;
//             if (122 < ri) ri = 97 + (ri - 123);
//         }

//         cout << char(ri) << "";
//     }

//     cout << "\n";

//     return 0;
// }