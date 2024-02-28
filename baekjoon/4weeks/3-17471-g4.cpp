#include <bits/stdc++.h>
using namespace std;

/*
    날짜: 2024-02-29
	횟수: 1
*/

const int INF = 987654321;
const int MAX_N = 12;
int n, arr_n, t;
vector<int> arr_v[MAX_N];
int visited[MAX_N];
char zones[MAX_N];
int counts[MAX_N];
int result = INF;

// a -> 0 b -> 1
// [1, 2, 3, 4, 5, 6]; -> 배열 담아 둘 필요 없음
// counts[n] [5, 2, 3, 4, 1, 2]; -> counts는 순서대로 담아놓으면 됨!
// zones[n] [a, a, a, b, b, b]; -> 지역구도 순서대로 담아놓으면 됨!

void dfs(int n) {
    visited[n] = 1;
    // cout << "n: " << n << " " << zones[n] << " ny: ";
    // for (int ny: arr_v[n]) {
    //     cout << ny << " ";
    // }
    // cout << "\n";
    for (int ny: arr_v[n]) {
        if (zones[ny] != zones[n]) continue;
        if (visited[ny]) continue;
        dfs(ny);
    }
}
bool is_valid() {
    memset(visited, 0, sizeof(visited));
    // for (int i=0; i<n; i++) {
    //     cout << zones[i] << " ";
    // }
    // cout << "\n";
    bool result = false;
    int a_compos = 0, b_compos = 0;
    for (int i=0; i<n; i++) {
        if (!visited[i]) {
            dfs(i);
            zones[i] == 'a' ? a_compos++ : b_compos++;
        }
    }
    if (a_compos == 1 && b_compos == 1) result = true;
    // cout << a_compos << " " << b_compos << "\n";
    return result;
}
int get_result() {
    int a_sum = 0, b_sum = 0;
    for (int i=0; i<n; i++) {
        zones[i] == 'a' ? a_sum += counts[i] : b_sum += counts[i];
    }

    return abs(a_sum-b_sum);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> counts[i];
    }
    for (int i=0; i<n; i++) {
        cin >> arr_n;
        for (int j=0; j<arr_n; j++) {
            cin >> t;
            arr_v[i].push_back(t-1);
        } 
    }
    for (int i=1; i<(1<<n)-1; i++) {
        memset(zones, 'a', sizeof(zones));
        for (int j=0; j<n; j++) {
            if (i&(1<<j)) {
                zones[j] = 'b';
            }
        }

        // 비트마스킹에 의해 갱신된 zones로부터 로직 실행
        // 하나의 지역구에 대해서 컴포넌트 갯수가 2개 이상이면 값 갱신 필요 x
        if (is_valid()) {
            result = min(result, get_result());
        }
    }

    if (result == INF) cout << -1 << '\n';
    else cout << result << '\n';
    
    return 0;
}