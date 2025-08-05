// 문자열 뒤집기
string s1 = "it will be reversed";
reverse(s1.begin(), s1.end());

// 문자열 자르기
string s2 = "it will be sliced";
s2.substr(0, s2.size());

// split
vector<string> split(string input, string delimiter) { 
    vector<string> ret;
    long long pos = 0;
    string token = "";
    while ((pos = input.find(delimiter)) != string::npos) { 
        token = input.substr(0, pos); 
        ret.push_back(token);
        input.erase(0, pos + delimiter.length());
    } 
    ret.push_back(input); 
    return ret;
}
