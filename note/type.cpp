// char to string
string(1, val);

/* string to int
    c_str(): c++ std::string 타입을 c의 char*, char[]로 변환해준다.
    - "asdf" -> 0
    - "0" -> 0
    - "123" -> 123
*/
atoi(val.c_str());