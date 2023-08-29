// https://www.acmicpc.net/problem/17298

/*
    날짜: 2023-08-29
	횟수: 1
    메모: 다시 한 번 더 풀 것.
*/
#include <bits/stdc++.h>
using namespace std;

int n, arr[1000004], ret[1000004];
stack<int> stk;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    memset(ret, -1, sizeof(arr));

    for (int i=0; i<n; i++) {
        cin >> arr[i];

        while (stk.size() && arr[stk.top()] < arr[i]) {
            ret[stk.top()] = arr[i];
            stk.pop();
        }
        
        stk.push(i);
    }

    for (int j=0; j<n; j++) {
        cout << ret[j] << " ";
    }

    return 0;
}