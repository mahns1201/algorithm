#include<bits/stdc++.h>
using namespace std;

string input;
int ret = 0;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> input;
  string prev = input;
  reverse(input.begin(), input.end());

  if (prev == input) {
    ret = 1;
  }
  
  cout << ret << "\n";
}