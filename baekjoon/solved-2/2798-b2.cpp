// https://www.acmicpc.net/problem/2798

#include <bits/stdc++.h>
using namespace std;

int N, M, ret;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;

    int arr[N];
    for (int i=0; i<N; i++) {
        cin >> arr[i];
    }

    for (int x=0; x<N; x++) {
        for (int y=1; y<N; y++) {
            for (int z=2; z<N; z++) {
                if (x == y || x == z || y == z) break;
                int t = arr[x] + arr[y] + arr[z];
                // cout << "t: " << t << "\n";
                if (t <= M && ret < t) ret = t;
            }
        }
    }

    cout << ret << "\n";

    return 0;
}