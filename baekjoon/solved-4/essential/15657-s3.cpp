#include <bits/stdc++.h>

/*
	날짜: 2024-04-05
	횟수: 1
*/

using namespace std;

int n, r;
int arr[10];
vector<int> v;

void make_p() {
    if(v.size() == r) {
        for(int idx: v) cout << arr[idx] << ' ';
        cout << '\n';
        return;
    }

    for(int i=0; i<n; i++) {
        if(v.size() && v[v.size()-1] > i) continue;
        v.push_back(i);
        make_p();
        v.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> r;
    for(int i=0; i<n; ++i) {
        cin >> arr[i];
    }
    sort(arr, arr+n);

    make_p();
    
    return 0;
}