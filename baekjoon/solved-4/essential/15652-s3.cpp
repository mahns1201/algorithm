#include <iostream>
#include <vector>

using namespace std;

/*
	날짜: 2024-04-05
	횟수: 1
*/

int n, r;
vector<int> v;

void make_p() {
    if(v.size() == r) {
        for(int it: v) cout << it << ' ';
        cout << '\n';
        return;
    }

    for(int i=1; i<n+1; i++) {
        if(v.size() && v[v.size()-1] > i) continue;
        v.push_back(i);
        make_p();
        v.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> r;

    make_p();

    
    return 0;
}