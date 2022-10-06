#include<iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

/*
    stoi(), to_string() : int ~ string
    getline(istringstream, string, 'delimiter') : iss에서 delimiter까지 읽어서 string에 저장함
    push_back() : 뒤에 추가
    vector.size() : 벡터길이
    string.length() : 스트링 길이
    max(a, b), min(a, b) : 최대최소값
*/


//함수선언부
vector<string> split(string str, char delimiter);

//구현부
int main(){
    string s = "-1 2 3 4";
    vector<string> tmp = split(s, ' ');
    int whatmax = stoi(tmp[0]);
    int whatmin = stoi(tmp[0]);
    for (int i=0; i<tmp.size(); i++){
        whatmax = max(whatmax, stoi(tmp[i]));
        whatmin = min(whatmin, stoi(tmp[i]));
    }
    cout << to_string(whatmin) + " " + to_string(whatmax) << endl;
}

// #include <sstream>, istringstream, getline 필요
vector<string> split(string str, char Delimiter) {
    istringstream iss(str);             // istringstream에 str을 담는다.
    string buffer;                      // 구분자를 기준으로 절삭된 문자열이 담겨지는 버퍼
    vector<string> result;
 
    // istringstream은 istream을 상속받으므로 getline을 사용할 수 있다.
    while (getline(iss, buffer, Delimiter)) { // iss에서 Delimiter까지 읽고 그걸 buffer에 넣는다.
        result.push_back(buffer);               // 절삭된 문자열을 vector에 저장
    }
 
    return result;
}