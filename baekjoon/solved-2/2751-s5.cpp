// https://www.acmicpc.net/problem/2751

/*
    날짜: 2023-09-06
	횟수: 1
    메모: 더 빠르게 푸는 방법이 있나?
*/
#include <bits/stdc++.h>
using namespace std;

int t;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    int arr[t];
    for (int i=0; i<t; i++) cin >> arr[i];
    sort(arr, arr+t);
    for (int it: arr) cout << it << "\n";

    return 0;
}