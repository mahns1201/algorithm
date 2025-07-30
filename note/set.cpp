s.clear();- 모든 원소를 제거합니다.
s.count(k);- 원소 k 의 갯수를 반환합니다 - set에서는 무조건  0,1 개 겠죠 ? -> multiset은 키값이 중복이 가능하기때문에 거기서 쓰입니다.
s.empty();- set s가 비어있는지 확인합니다.
s.insert(k);- 원소 k를 삽입합니다.- 삽입시에 자동으로 정렬된 위치에 삽입됩니다.- 삽입이 성공 실패에 대한 여부는 리턴값 (pair<iterator, bool>) 으로 나오게됩니다.- pair<iterator, bool>에서 pair.first는 삽입한 원소를 가리키는 반복자 이고, pair.second는 성공(true), 실패(false)를 나타냅니다.
s.insert(iter, k);- iter가 가리키는 위치 부터 k를 삽입할 위치를 탐색하여 삽입합니다.
s.erase(iter);- iter가 가리키는 원소를 제거합니다.- 제거 한다음 제거 한 원소 다음 원소를 가리키는 반복자를 리턴합니다.s.erase(start, end);- [start, end) 범위의 원소를 모두 제거합니다.
s.find(k);- 원소 k를 가리키는 반복자를 반환합니다.- 원소 k가 없다면 
s.end() 와 같은 반복자를 반환합니다.
s2.swap(s1);- s1과 s2를 바꿔줍니다.
s.upper_bound(k);- 원소 k가 끝나는 구간의 반복자 입니다.
s.lower_bound(k);- 원소 k가 시작하는 구간의 반복자 입니다.
s.equal_range(k);    - 원소 k가 시작하는 구간과 끝나는 구간의 반복자 pair 객체를 반환합니다.- 
upper_bound(k), lower_bound(k) 가 합쳐진 멤버함수
s.value_comp();s.key_comp();- 정렬 기준 조건자를 반환합니다.- set 컨테이너에서는 두개의 함수 반환형이 같습니다.s.
size();- 사이즈(원소의 갯수)를 반환합니다.
s.max_size();- 최대 사이즈(남은 메모리 크기)를 반환합니다.