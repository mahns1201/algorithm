#include <bits/stdc++.h>
using namespace std;

/*
	날짜: 2024-01-17
	횟수: 1*
    특이사항: 왜 성공인지 잘 모르겠다. 정렬할 때 bool return의 기준을 명확히 파악하자.
*/

int n;
string s;
vector<string> v;

bool cmp(string a, string b) {
    if (a.size() == b.size()) return a < b;
    else return a.size() < b.size();
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> s;
        v.push_back(s);
    }

    // v.erase(unique(v.begin(),v.end()),v.end());
    // sort(v.begin(), v.end(), cmp);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    sort(v.begin(), v.end(), cmp);

    // cout << "\n\n\n";
    for (int i=0; i<v.size(); i++) {
        cout << v[i] << "\n";
    }

    return 0;
}