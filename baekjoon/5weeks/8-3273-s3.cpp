#include <bits/stdc++.h>
using namespace std;

/*
    날짜: 2024-04-09
	횟수: 1
    메모: 다시 풀어라.
*/

int n, t, x, result;
vector<int> v;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> t;
        v.push_back(t);
    }
    cin >> x;

    sort(v.begin(), v.end());

    int start = 0;
    int end = n-1;

    while(start < end) {
        int _sum = v[start] + v[end];
        
        if(_sum < x) {
            ++start;
        }else if(_sum > x) {
            --end;
        }else {
            ++result;
            ++start;
            --end;
        }
    }

    cout << result << '\n';

    return 0;
}