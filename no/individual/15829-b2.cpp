// https://www.acmicpc.net/problem/15829

/*
    날짜: 2023-08-06
    특이사항: 50점 짜리 답안, 100점 짜리 답안 추가 (이해 x)
*/
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

// #include <bits/stdc++.h>
// using namespace std;
// #define r 31
// #define M 1234567891

// int N;
// string I;
// long long ret;
// int main() {
//     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//     cin >> N >> I;

//     long long R=1;
//     for (int i=0; i<N; i++) {
//         ret += ((I[i] - 96) * R) % M; ret %= M;
//         R = R * 31 % M;
//     }

//     cout << ret << "\n";
    
//     return 0;
// }