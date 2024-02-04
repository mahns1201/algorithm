#include <bits/stdc++.h>
using namespace std;

/*
	날짜: 2024-02-04
	횟수: 1
    메모: c++ std::binary_search (<algorithm>)에 binary_search를 제공한다.
*/

int n, m;
string name;
vector<string> v;
vector<string> result;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    
    for (int i=0; i<n; i++) {
        cin >> name;
        v.push_back(name);
    }
    sort(v.begin(), v.end());
    
    for (int i=0; i<m; i++) {
        cin >> name;
        if (binary_search(v.begin(), v.end(), name)) result.push_back(name);
    }
    
    sort(result.begin(), result.end());
    cout << result.size() << "\n";
    for (auto ret: result) cout << ret << "\n";

    return 0;
}