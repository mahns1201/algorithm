// 왕비를 피해 일곱 난쟁이들과 함께 평화롭게 생활하고 있던 백설공주에게 위기가 찾아왔다. 
// 일과를 마치고 돌아온 난쟁이가 일곱 명이 아닌 아홉 명이었던 것이다.
// 아홉 명의 난쟁이는 모두 자신이 "백설 공주와 일곱 난쟁이"의 주인공이라고 주장했다. 
// 뛰어난 수학적 직관력을 가지고 있던 백설공주는, 다행스럽게도 일곱 난쟁이의 키의 합이 100이 됨을 기억해 냈다.
// 아홉 난쟁이의 키가 주어졌을 때, 백설공주를 도와 일곱 난쟁이를 찾는 프로그램을 작성하시오.

#include <bits/stdc++.h>
using namespace std;

int a[9];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  for (int i=0; i<9; i++) {
    cin >> a[i];
  }

  sort(a, a+9);
  
  do {
    int sum = 0;
    for (int i=0; i<7; i++) {
      sum += a[i];
    }

    if (sum == 100) {
      for (int j=0; j<7; j++) {
        cout << a[j] << "\n";
      }
      break;
    }
    
    

  } while(next_permutation(a, a+9));
  
  return 0;
}

// 2회차 - 1
// next_permutation()

// #include <bits/stdc++.h>
// using namespace std;

// int input;
// vector<int> v;

// void printAnswer(vector<int> &v) {
//     for (int i=0; i<7; i++) {
//         cout << v[i] << "\n";
//     }
//     exit(0);
// }

// int main() {
//     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

//     for (int i=0; i<9; i++) {
//         cin >> input;
//         v.push_back(input);
//     }

//     sort(v.begin(), v.end());
    
//     do {
//         int ret = 0;
//         for (int j=0; j<7; j++) {
//             ret += v[j];
//         }
//         if (ret == 100) printAnswer(v);
//     } while(next_permutation(v.begin(), v.end()));

//     return 0;
// }


// 2회차 - 1
// 재귀함수

// #include <bits/stdc++.h>
// using namespace std;

// int arr[9];

// void makePermutation(int n, int r, int depth) {
//     if (r == depth) {
//         int ret = 0;
//         for (int i=0; i<7; i++) {
//             ret += arr[i];
//         }

//         if (ret == 100){
//             sort(arr, arr+7);
//             for (int i=0; i<7; i++) {
//                 cout << arr[i] << "\n";
//             }
//             exit(0);
//         }
//     } 

//     for (int j = depth; j < n; j++) {
//         swap(arr[j], arr[depth]);
//         makePermutation(n, r, depth+1);
//         swap(arr[j], arr[depth]);
//     }

//     return;
// }


// int main() {
//     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

//     for (int i=0; i<9; i++) {
//         cin >> arr[i];
//     }

//     makePermutation(9, 7, 0);

//     return 0;
// }