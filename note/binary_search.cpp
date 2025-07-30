int check(int val, vector<int> &v) {
    int l = 0; r = v.size() - 1;
    
    while(l <= r) {
        int mid = (l + r) / 2;

        if(v[mid] > val) r = mid - 1;
        else if(v[mid == val]) return 1;
        else l = mid + 1;
    }
    
    return 0;
}

/*
문제: https://www.acmicpc.net/problem/2776
랭크: S4

```c++
#include <bits/stdc++.h>
using namespace std;

int T, n, m, t;

int check(int val, vector<int> &v) {
    int l = 0, r = v.size() - 1;
    
    while(l <= r) {
        int mid = (l + r) / 2;

        if(v[mid]  == val) {
            return 1;
        } 

        if(v[mid] > val) r = mid - 1;
        else l = mid + 1;
    }
    
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> T;

    while(T--) {
        vector<int> v1;
        cin >> n;
        for(int i=0; i<n; i++) {
            cin >> t;
            v1.push_back(t);
        }

        sort(v1.begin(), v1.end());

        cin >> m;
        for(int i=0; i<m; i++) {
            cin >> t;
            cout << check(t, v1) << "\n";
        }
    }

    return 0;
}
```
*/