// char to string
string a = string(1, 'a');

// char to ASCII
int char_to_ascii = (int) '3'

// char to int
int char_to_int = '3' - '0';

/* string to int
    c_str(): c++ std::string 타입을 c의 char*, char[]로 변환해준다.
    - "asdf" -> 0
    - "0" -> 0
    - "123" -> 123
*/
int string_to_int = atoi("1231");