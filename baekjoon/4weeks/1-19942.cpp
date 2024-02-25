#include <bits/stdc++.h>
using namespace std;

/*
    날짜: 2024-02-18
	횟수: 1*
    메모: 구조체와 구조체의 배열, vector<vector<int>>에서의 sort
*/

// const int INF = 987654321;
int ret = 987654321;
int n, mp, mf, ms, mv;
int p, f, s, v, price;
struct A {
    int a, b, c, d, e;
} arr[16];
map<int, vector<vector<int>>> result;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> mp >> mf >> ms >> mv;
    
    for (int i=0; i<n; i++) {
        cin >> arr[i].a >> arr[i].b >> arr[i].c >> arr[i].d >> arr[i].e;
    }
    for (int i=1; i<(1<<n); i++) {
        int aa = 0, bb = 0, cc = 0, dd = 0, price = 0;
        vector<int> v;
        for (int j=0; j<n; j++) {
            if (i&(1<<j)) {
                v.push_back(j+1);
                aa += arr[j].a;
                bb += arr[j].b;
                cc += arr[j].c;
                dd += arr[j].d;
                price += arr[j].e;
            }
        }

        if (aa>=mp && bb>=mf && cc>=ms && dd>=mv) {
            if (ret>=price) {
                ret = price;
                result[ret].push_back(v);
            }
        }
    }
    
    if (ret == 987654321) {
        cout << "-1\n";
    } else {
        cout << ret << "\n";
        sort(result[ret].begin(), result[ret].end());
        for (int i: result[ret][0]) cout << i << " ";
        cout << "\n";
    }

    return 0;
}