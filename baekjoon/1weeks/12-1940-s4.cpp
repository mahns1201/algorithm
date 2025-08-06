// https://www.acmicpc.net/problem/1940

/*
    날짜: 2025-08-06
    횟수: 3
    특이사항: 투포인터로 잘 풀었다. 포인터의 범위를 잘 생각할 것. 정렬 기준은 오름차순이 좋음.
*/
#include <bits/stdc++.h>
using namespace std;

int n, m, t, lp, rp, ret;
vector<int> v;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        cin >> t;
        v.push_back(t);
    }
    sort(v.begin(), v.end(), greater<>());

    rp = n - 1;

    // for (auto it: v) {
    //     cout << it << " ";
    // }

    // cout << lp << " " << rp << "\n";

    while (lp < rp) {
        // cout << lp << " " << rp << ": " << arr[lp] + arr[rp] << "\n";
        if (v[lp] + v[rp] == m) {
            ret++;
            lp++;
            rp--;
        } else if (v[lp] + v[rp] < m) {
            rp--;
        } else {
            lp++;
        }
    }

    cout << ret << "\n";

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// int N, M, ret;
// int li[10000004];
// int main() {
//   ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

//   cin >> N >> M;
//   int n;
//   for(int i=0; i<N; i++) {
//     cin >> n;
//     li[i] = n;
//   }


//   // 이렇게 하지말고 2중 for문 사용해서 nCr 구현 해보기 (i만 사용하면 됨)
//   // 다른 방법으로 조합 구현 확인.
//   int temp=0;
//   for (int j=0; j<N; j++) {
//     temp += 1;
//     for (int k=temp; k<N; k++){
//       cout << j << "+" << k << ": " << li[j] + li[k] << "\n";

//       if (li[j] + li[k] == M) {
//         ret += 1;
//       }
//     }
//   }

//   cout << ret << "\n";

//   return 0;
// }


/*
	날짜: 2023-08-07
	횟수: 2
  특이사항: 3회차에선 cnt/2를 없앨 수 있는 방법을 생각해봐라.
*/
// int N, M, cnt;
// int main() {
//     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//     cin >> N >> M;
//     int arr[N];
//     for (int i=0; i<N; i++) {
//         int temp;
//         cin >> temp;
//         arr[i] = temp;
//     }

//     for (int j: arr) {
//         for (int k: arr) {
//             if (M == j+k) {
//                 cnt++;
//             }
//         }
//     }

//     cout << cnt/2 << "\n";

//     return 0;
// }
