#include <bits/stdc++.h>
using namespace std;

/*
	날짜: 2024-02-08
	횟수: 1
    메모: split 다시 암기해라.
*/

int result;
string input;
vector<int> ret;

vector<string> split(string input, string delimiter) {
    vector<string> ret;
    long long pos = 0;
    string token = "";
    while ((pos = input.find(delimiter)) != string::npos) {
            token = input.substr(0, pos);
            ret.push_back(token);
            input.erase(0, pos + delimiter.length());
    } ret.push_back(input);
    return ret;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> input;
    
    vector<string> v = split(input, "-");
    for (auto s: v) {
        int _sum = 0;
        vector<string> vv = split(s, "+");
        for (string ss: vv) _sum += stoi(ss);
        ret.push_back(_sum);
    }

    result = ret[0];
    for (int i=1; i<ret.size(); i++) result -= ret[i];
    cout << result << "\n";

    return 0;
}