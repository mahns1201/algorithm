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

/*
	날짜: 2023-12-21
	횟수: 2
*/
// #include <string>
// #include <vector>

// using namespace std;

// int answer = 0;
// int t_target;
// vector<int> t_numbers;

// void dfs(int curr, int depth) {
//     if (depth == t_numbers.size()) {
//         if (curr == t_target) answer++;
//         return;
//     }
    
//     dfs (curr + t_numbers[depth], depth + 1);
//     dfs (curr - t_numbers[depth], depth + 1);
// }

// int solution(vector<int> numbers, int target) {
//     t_numbers = numbers;
//     t_target = target;
    
//     dfs(0, 0);
    
//     return answer;
// }
