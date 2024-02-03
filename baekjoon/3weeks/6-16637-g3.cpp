#include <bits/stdc++.h>
using namespace std;

/*
    날짜: 2024-02-04
	횟수: 1*
    메모: 입력 받기 다시 연습, 생각하는 힘 기르자
*/

int n;
int result = -987654321;
string input;
vector<int> arr;
vector<char> oper;

int cal(int a, char oper, int b) {
    if (oper == '+') {
        return a+b;
    } else if (oper == '-') {
        return a-b;
    } else {
        return a*b;
    }
}

void go(int val, int idx, int cnt) {
    if (cnt == arr.size()-1) {
        result = max(result, val);
        return;
    }

    int curr;
    curr = cal(val, oper[idx], arr[idx+1]);
    go(curr, idx+1, cnt+1);

    if (idx+2 < arr.size()) {
        int curr = cal(arr[idx+1], oper[idx+1], arr[idx+2]);
        curr = cal(val, oper[idx], curr);
        go(curr, idx+2, cnt+2);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> input;

    // 효율적으로 입력 받는 법
    // for(int i = 0; i < n; i++){
    //     if(i % 2 == 0)num.push_back(s[i] - '0');
    //     else oper_str.push_back(s[i]);
    // } 

    for (int i=0; i<input.size(); i++) {
        if (i == 0) {
            arr.push_back(int(input[i])-48);
        } else if (i%2 == 0) {
            arr.push_back(int(input[i])-48);
        } else {
            oper.push_back(input[i]);
        }
    }

    go(arr[0], 0, 0);

    cout << result << "\n";

    return 0;
}