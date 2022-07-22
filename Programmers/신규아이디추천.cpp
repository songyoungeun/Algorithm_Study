#include <string>
#include <vector>
#include <iostream>
#include <regex>
using namespace std;

string solution(string new_id) {
    string answer = "";
    //모두 소문자로 치환
    for(auto tmp : new_id){
        answer += tolower(tmp);
    }
    // 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자열 제거
    answer = regex_replace( answer , regex("[^a-z0-9-_.]+"), "" );
    
//    for (char& ch: new_id) {
//    	if ('a' <= ch && ch <= 'z' ||
//            '0' <= ch && ch <= '9' ||
//            strchr("-_.", ch)) ret += ch;
//    }
	// . 2번이상 제거
//    answer = regex_replace(answer, regex("[.]+"), ".");
	string ret;
	for(char& ch : answer){
		if(!ret.empty() && ret.back() == '.' && ch == '.') continue;
		ret += ch;
	}
	answer = ret;
    //. 첨/끝 제거
    
    if(answer[0] == '.') answer.erase(answer.begin());
    if(answer[answer.size()-1] == '.') answer.erase(answer.end() -1);
    
    //빈문자열 a대입
    if(answer.empty()){
        answer = "a";
    }
    //16이상이면 15까지 제거
    if(answer.size() >= 16) answer = answer.substr(0,15);
    if(answer.back() == '.') answer.pop_back();
//    if(answer[answer.size()-1] == '.') answer.erase(answer.end() -1);
//    if(answer.length() >= 16){
//        answer.erase(15);
//        if(answer[answer.size()-1] == '.')answer.erase(answer.end() -1);
//    }
//    
    //2이하면 마지막 문자로 3까지 늘리기
//    if(answer.length() <= 2){
//        char a = answer[answer.size()-1];
//        while(answer.length() < 3){
//            answer.push_back(a);
//        }
//    }
	while(answer.size() <= 2){
		answer += answer.back();
	}   
    return answer;
}
