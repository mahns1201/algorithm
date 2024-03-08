#include <bits/stdc++.h>
using namespace std;

/*
    날짜: 2024-03-08
	횟수: 1
    메모: 이런 발상은 어떻게 할 수 있을까.. 다시 풀어보자.
*/

int n, l, ret;
int cnt = 1, before;
int mp[104][104];
int mp_2[104][104];
void cal(int a[104][104]){
    for(int i=0; i<n; i++){
        cnt = 1;
        int j;
        for(j=0; j<n-1; j++){
            if(a[j][i] == a[j+1][i]){
                cnt++;
            }else if(a[j][i]+1 == a[j+1][i] && cnt>=l){
                cnt = 1;
            }else if(a[j][i]-1 == a[j+1][i] && cnt>=0){
                cnt = -l+1;
            }else break;
        }
        if (j==n-1 && cnt>=0) ret++;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >>n >> l;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> mp[i][j];
            mp_2[j][i] = mp[i][j];
        }
    }

    cal(mp);
    cal(mp_2);

    cout << ret << '\n';

    return 0;
}