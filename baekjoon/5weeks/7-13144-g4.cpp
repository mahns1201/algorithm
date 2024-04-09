#include <bits/stdc++.h>
using namespace std;

/*
    날짜: 2024-04-10
	횟수: 1
    메모: 경우의 수 문제일 경우 정답을 long long으로 처리하자.
*/

const int MAX_N = 100004;
long long result;
int n, t;
vector<int> v;
int visited[MAX_N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> t;
        v.push_back(t);
    }

    int start=0, end=0;
    while(end<=n) {
        if(!visited[v[end]]) {
            ++visited[v[end]];
            ++end;
        }else {
            result += (end - start);
            --visited[v[start]];
            ++start;
        }
    }

    result += (long long)(end-start)*(end-start-1)/2;
    cout << result << '\n';

    return 0;
}