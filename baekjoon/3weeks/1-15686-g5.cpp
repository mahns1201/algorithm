#include <bits/stdc++.h>

using namespace std;

int N, M, in, result;
vector<vector<int>> combChickenList;
vector<pair<int, int>> homeList, chickenList;
void comb(int start, vector<int> v) {
    if (v.size() == M) {
        combChickenList.push_back(v);
        return;
    }

    for (int i=start+1; i<chickenList.size(); i++) {
        v.push_back(i);
        comb(i, v);
        v.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for (int x=0; x<N; x++) {
        for (int y=0; y<N; y++) {
            cin >> in;
            if (in == 1) {
                homeList.push_back({y, x});
            } else if (in == 2) {
                chickenList.push_back({y, x});
            }
        }
    }

    vector<int> v;
    comb(-1, v);

    int result = 987654321;
    for (auto chickenSet: combChickenList) {
        int ret=0;
        for (auto home: homeList) {
            int chickenLength = 987654321;
            for (auto c: chickenSet) {
                chickenLength = min(chickenLength, abs(home.first - chickenList[c].first) + abs(home.second - chickenList[c].second));
            }
            ret += chickenLength;
        }
        result = min(result, ret);
    }

    cout << result << "\n";

    return 0;
}