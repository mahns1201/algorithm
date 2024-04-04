#include <iostream>
#include <queue>

using namespace std;

/*
    날짜: 2024-04-05
	횟수: 1
    메모: 숫자 n이 주어졌을 때, 1~n 사이의 소수 찾는 함수 구현
*/

int n, result;
vector<int> primes;

bool is_prime(int num) {
    bool prime = true;
    for(int i=2; i*i<=num; i++) {
        if(num%i == 0) {
            prime = false;
            break;
        }
    }

    return prime;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    
    for(int i=2; i<=n; ++i) {
        if(is_prime(i)) primes.push_back(i);
    }

    int ret = 0;
    priority_queue<int> pq;
    for(int i=primes.size()-1; i>=0; --i) {
        ret += primes[i];
        pq.push(primes[i]);
        if(ret > n) {
            ret -= pq.top();
            pq.pop();
        }else if(ret == n) {
            ret -= pq.top();
            pq.pop();
            result++;
        }
    }

    cout << result << '\n';
    
    return 0;
}