// https://www.acmicpc.net/problem/2852

/*
    날짜: 2023-09-06
	횟수: 1
    메모: 다시 한 번 더 풀 것.
*/
#include <bits/stdc++.h>
using namespace std;

int t, team, a, b;
string ttime, pre;
int a_sum, b_sum;

string format_to_answer(int s) {
    string mm = "00" + to_string(s/60);
    string ss = "00" + to_string(s%60);
    return mm.substr(mm.size() -2, 2) + ":" + ss.substr(ss.size() -2, 2);
}

int to_second(string tt) {
    return (stoi(tt.substr(0, 2)) * 60 + stoi(tt.substr(3, 5)));
}

void go_go(int &ss, string tt) {
    ss += (to_second(tt) - to_second(pre));
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--) {
        cin >> team >> ttime;
        // cout << "\n";
        if (a>b) go_go(a_sum, ttime);
        else if (b>a) go_go(b_sum, ttime);
        team == 1 ? a++ : b++;
        pre = ttime;
    }

    if (a>b) go_go(a_sum, "48:00");
    else if (b>a) go_go(b_sum, "48:00");

    cout << format_to_answer(a_sum) << "\n";
    cout << format_to_answer(b_sum) << "\n";


    return 0;
}