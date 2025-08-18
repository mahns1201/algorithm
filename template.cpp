// https://www.acmicpc.net/problem/xxxx

#include <bits/stdc++.h>
using namespace std;

/*
	날짜: yyyy-mm-dd
	횟수: unsigned int
    메모: commit messages: [no-level] try (Add an asterisk (*) to try again)
*/

int main() {
    // Add this to increase C++ I/O speed. (about 10 times)
    /*
        C의 stdio (printf, scanf 등)와 C++의 iostream (cin, cout 등)을 분리
        기본적으로 C++의 cin/cout은 C의 stdio와 동기화(synchronize)되어 있어 느림 -> false로 하면 동기화를 끊어서 C++ 스트림만 빠르게 사용

        부작용: 이후에 printf/scanf(C)와 cin/cout(C++)을 섞어 쓰면 버그 위험하므로 C++ 입출력만 쓰는 경우에만 설정해야 함
        추가: endl 대신 '\n'을 쓸 때 더 빠름 (endl은 flush를 강제로 수행)
    */
    ios_base::sync_with_stdio(false);
    /*
        cin과 cout의 묶음을 해제 (기본적으로 cin 사용시, cout 버퍼를 자동 flush함. 느려짐)
        tie를 끊으면, cin이 입력을 기다릴 때마다 cout이 강제로 출력되는 현상이 없어져 속도 향상
        
        주의: 묶음을 해제해도 출력이 밀릴 수 있으니, 마지막에 flush(endl 등) 필요할 수 있음
    */
    cin.tie(nullptr);

    return 0;
}
