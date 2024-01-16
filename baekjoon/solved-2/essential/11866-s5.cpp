#include <bits/stdc++.h>
using namespace std;

int n, k, current_idx;
vector<int> v;
vector<int> ret;
int get_index(int current, int v_size) {
    int ret = current + k - 1;
    if (v_size == ret) return 0;
    else if (v_size < ret) return ret % v_size;
    else return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;

    for (int i=0; i<n; i++) {
        v.push_back(i+1);
    }

    while (v.size()) {
        // cout << current_idx << " " << v.size() << " ";
        // cout << current_idx << " " << v.size() << "\n";
        current_idx = get_index(current_idx, v.size());
        // cout << current_idx << "\n";
        ret.push_back(v[current_idx]);
        v.erase(v.begin() + current_idx);
    }

    cout << "<";
    for (int i=0; i<ret.size(); i++) {
        if (i == ret.size()-1) cout << ret[i];
        else cout << ret[i] << ", ";
        
    }
    cout << ">\n";

    return 0;
}