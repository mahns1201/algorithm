https://school.programmers.co.kr/learn/courses/30/lessons/43165

#include <string>
#include <vector>

using namespace std;

int answer = 0;

void rFn(vector <int> numbers, int target, int result) {
    // numbers.size()가 0이면 target == result 확인
  if (!numbers.size()) {
      if (target == result) answer++;
      return;
  }
  
  // current를 number에 가장 앞에 것을 할당 
  int current = numbers.front(); numbers.erase(numbers.begin());

  rFn(numbers, target, result+current);
  rFn(numbers, target, result-current);
}

int solution(vector<int> numbers, int target) {
  rFn(numbers, target, 0);
  return answer;
}