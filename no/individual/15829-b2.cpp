// https://www.acmicpc.net/problem/15829

#include <bits/stdc++.h>
using namespace std;

int N;
string I;
long long ret;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> I;

    for (int i=0; i<N; i++) {
        ret += (I[i] - 96) * pow(31, i);
    }

    cout << ret << "\n";
    
    return 0;
}