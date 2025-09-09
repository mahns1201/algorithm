// https://www.acmicpc.net/problem/15686

#include <bits/stdc++.h>
using namespace std;

/*
	날짜: 2025-09-09
	횟수: 3*
    메모: 조합 만드는 부분 다시 복습.
*/

int n, r, result = 987654321;
int mp[54][54];
vector<pair<int, int>> chickens;

int get_chicken_num() {
    int result = 0;

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            int ret = 987654321;
            if (mp[i][j] != 1) continue;
            for (pair<int, int> it: chickens) {
                if (mp[it.first][it.second] != 2) continue;
                ret = min(ret, abs(it.first - i) + abs(it.second - j));
            }
            result += ret;
        }
    }
    // cout << "result: " << result << "\n";
    return result;
}

void comb(int start, vector<int> v) {
    if (v.size() == r) {
        // 치킨집 r 갯수 만큼 뽑고 나머지 0으로 변경
        for (int i=0; i<chickens.size(); i++) {
            if (find(v.begin(), v.end(), i) != v.end()) continue;
            mp[chickens[i].first][chickens[i].second] = 0;
        }

        // cout << "!" << "\n";
        // for (int i=0; i<n; i++) {
        //     for (int j=0; j<n; j++) {
        //         cout << mp[i][j] << " ";
        //     }
        //     cout << "\n";
        // }

        result = min(result, get_chicken_num());

        // 치킨집 원복
        for (int i=0; i<chickens.size(); i++) {
            mp[chickens[i].first][chickens[i].second] = 2;
        }

        // cout << "!!" << "\n";
        // for (int i=0; i<n; i++) {
        //     for (int j=0; j<n; j++) {
        //         cout << mp[i][j] << " ";
        //     }
        //     cout << "\n";
        // }

        return;
    }

    for (int i=start+1; i<chickens.size(); i++) {
        v.push_back(i);
        comb(i, v);
        v.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    
    cin >> n >> r;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> mp[i][j];
            if (mp[i][j] == 2) chickens.push_back({ i, j });
        }
    }

    vector<int> v;
    comb(-1, v);

    cout << result << "\n";

    return 0;
}

/*
	날짜: ?
	횟수: 1
*/

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