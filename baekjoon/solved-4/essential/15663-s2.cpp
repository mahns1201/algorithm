#include <bits/stdc++.h>
using namespace std;

/*
	날짜: 2024-04-01
	횟수: 1
    메모: 한 번 더 풀어봐라
*/

int n, r;
int arr[10];
int visited[10];
vector<int> v;

void dfs(int depth) {
    if(depth==r) {
        for(int i=0; i<r; i++) cout << v[i] << ' ';
        cout << '\n';
        return;
    }

    int temp = 0;
    for(int i=0; i<n; i++) {
        if(visited[i]) continue;
        if(temp == arr[i]) continue;
        visited[i] = 1;
        v.push_back(arr[i]);
        temp = arr[i];
        dfs(depth+1);
        visited[i] = 0;
        v.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> r;
    for(int i=0; i<n; i++) cin >> arr[i];
    sort(arr, arr+n);

    dfs(0);

    return 0;
}