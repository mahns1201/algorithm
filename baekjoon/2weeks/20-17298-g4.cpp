// https://www.acmicpc.net/problem/17298

#include <bits/stdc++.h>
using namespace std;

/*
    날짜: 2025-09-08
	횟수: 2
    메모: 해당 코드를 읽어보고 다시 개선할 것. 입력 루프에서 ret을 갱신할 수 있다.
*/
int n, t;
pair<int, int> arr[1000004];
int ret[1000004];
stack<pair<int, int>> stk;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> t;
        arr[i] = { t, i };
    };
    
    memset(ret, -1, sizeof(ret));

    for (int i=0; i<n; i++) {
        while (stk.size() && stk.top().first < arr[i].first) {
            ret[stk.top().second] = arr[i].first;
            stk.pop();
        }
        
        stk.push(arr[i]);
    }

    for (int i=0; i<n; i++) cout << ret[i] << " ";
    cout << "\n";

    return 0;
}

/*
    날짜: 2023-08-29
	횟수: 1
    메모: 다시 한 번 더 풀 것.
*/
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