// https://www.acmicpc.net/problem/2609

#include <bits/stdc++.h>
using namespace std;

int N, M;
int retA, retB;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;

    if (N<M) {
        for (int i=N; i>0; i--) {
            if (N%i==0 && M%i==0) {
                retA = i;
                break;
            } 
        }

        for (int j=M; j<N*M+1; j++) {
            if (j%N==0 && j%M==0) {
                retB = j;
                break;
            }
        }
    } else {
        for (int i=M; i>0; i--) {
            if (N%i==0 && M%i==0) {
                retA = i;
                break;
            } 
        }

        for (int j=N; j<N*M+1; j++) {
            if (j%N==0 && j%M==0) {
                retB = j;
                break;
            }
        }
    }

    cout << retA << "\n" << retB << "\n"; 

    return 0;
}