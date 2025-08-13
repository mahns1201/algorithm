// https://www.acmicpc.net/problem/1992

#include <bits/stdc++.h>
using namespace std;

/*
    날짜: 2025-08-13
	횟수: 2
    특이사항: quad 함수 조건을 잘 생각해야 한다. / 분할정복으로 풀어봐야 한다.
*/
const int MAX = 65;
int n;
string s, result;
string mp[MAX][MAX];

string quad(string lt, string rt, string lb, string rb) {
    if (lt == rt && rt == lb && lb == rb) {
        if (lt == "0" || lt == "1") {
            return lt;
        }
    }

    return "(" + lt + rt + lb + rb + ")";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    
    if (n == 1) {
        cin >> s;
        cout << s << "\n";
        return 0;
    }

    for (int i=0; i<n; i++) {
        cin >> s;
        for (int j=0; j<s.size(); j++) {
            mp[i][j] = s[j];
        }
    }

    // cout << quad(mp[0][0], mp[0][1], mp[1][0], mp[1][1]) << "\n";

    // cout << "\n\n\n";

    while (n > 1) {
        for (int i=0; i<n; i+=2) {
            for (int j=0; j<n; j+=2) {
                mp[i/2][j/2] = quad(mp[i][j], mp[i][j+1], mp[i+1][j], mp[i+1][j+1]);
                // cout << i << " " << j << ": ";
                // cout << quad(mp[i][j], mp[i][1], mp[1][j], mp[1][1]) << "\n";
            }
            // cout << "\n";
        }

        // cout << "\n\n\n";

        n /= 2;
    }
    
    cout << mp[0][0] << "\n";

    return 0;
}

// int N;
// string I;
// string adj[68][68];

// string sumString(string lt, string rt, string lb, string rb) {
// 	if (lt == rt && rt == lb && lb == rb && rb == "1") return "1";
// 	else if (lt == rt && rt == lb && lb == rb && rb == "0") return "0";
// 	else return "(" + lt + rt + lb + rb + ")";
// }

// string dfs(int y, int x, int depth) {
// 	if (depth == 1) {
// 		return adj[0][0];
// 	}

// 	if (depth == 2) {
// 		return sumString(adj[y][x], adj[y][x+1], adj[y+1][x], adj[y+1][x+1]);
// 	}

// 	int divide = depth/2;
// 	string LT = dfs(y, x, divide);
// 	string RT = dfs(y, x+divide, divide);
// 	string LB = dfs(y+divide, x, divide);
// 	string RB = dfs(y+divide, x+divide, divide);

// 	return sumString(LT, RT, LB, RB);
// }

// int main() {
// 	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
// 	cin >> N;

// 	for (int i=0; i<N; i++) {
// 		cin >> I;
// 		for (int j=0; j<N; j++) {
// 			string a = I.substr(j, 1);
// 			adj[i][j] = a;
// 		}
// 	}

// 	cout << dfs(0, 0, N) << "\n";

// 	return 0;
// }