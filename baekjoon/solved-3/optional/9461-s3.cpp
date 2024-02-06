#include <bits/stdc++.h>
using namespace std;

/*
	날짜: 2024-02-06
	횟수: 1
*/

int t, n, max_n;
vector<int> numbers;
vector<long long> v;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;

    v.push_back(0);
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(2);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    for (int i=0; i<t; i++) {
        cin >> n;
        max_n = max(max_n, n);
        numbers.push_back(n);
    }

    if (max_n > 7) {
        for (int i=8; i<max_n+1; i++) {
            v.push_back(v[i-5] + v[i-1]);
        }
    }

    for (auto i: numbers) {
        cout << v[i] << "\n";
    }

    return 0;
}