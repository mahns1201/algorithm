int n; // 뽑고자 하는 표본의 수
int r; // 뽑는 수

void comb(int start, vector<int> v) {
    if (v.size() == r) {
        for(int it: v) cout << it+1 << ' ';
        cout << '\n';
        return;
    }

    for (int i=start+1; i<n; i++) {
        v.push_back(i);
        comb(i, v);
        v.pop_back();
    }
}

vector<int> v;
comb(-1, v);
