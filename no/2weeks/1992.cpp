https://www.acmicpc.net/problem/1992

#include <bits/stdc++.h>
using namespace std;

int N;
string I;
string adj[68][68];

string sumString(string lt, string rt, string lb, string rb) {
	if (lt == rt && rt == lb && lb == rb && rb == "1") return "1";
	else if (lt == rt && rt == lb && lb == rb && rb == "0") return "0";
	else return "(" + lt + rt + lb + rb + ")";
}

string dfs(int y, int x, int depth) {
	if (depth == 1) {
		return adj[0][0];
	}

	if (depth == 2) {
		return sumString(adj[y][x], adj[y][x+1], adj[y+1][x], adj[y+1][x+1]);
	}

	int divide = depth/2;
	string LT = dfs(y, x, divide);
	string RT = dfs(y, x+divide, divide);
	string LB = dfs(y+divide, x, divide);
	string RB = dfs(y+divide, x+divide, divide);

	return sumString(LT, RT, LB, RB);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;

	for (int i=0; i<N; i++) {
		cin >> I;
		for (int j=0; j<N; j++) {
			string a = I.substr(j, 1);
			adj[i][j] = a;
		}
	}

	cout << dfs(0, 0, N) << "\n";

	return 0;
}