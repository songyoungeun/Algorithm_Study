#include <string>
#include <vector>
#include <iostream>
#include <regex>
using namespace std;

string solution(string new_id) {
    string answer = "";
    //��� �ҹ��ڷ� ġȯ
    for(auto tmp : new_id){
        answer += tolower(tmp);
    }
    // ���ĺ� �ҹ���, ����, ����(-), ����(_), ��ħǥ(.)�� ������ ��� ���ڿ� ����
    answer = regex_replace( answer , regex("[^a-z0-9-_.]+"), "" );
    
//    for (char& ch: new_id) {
//    	if ('a' <= ch && ch <= 'z' ||
//            '0' <= ch && ch <= '9' ||
//            strchr("-_.", ch)) ret += ch;
//    }
	// . 2���̻� ����
//    answer = regex_replace(answer, regex("[.]+"), ".");
	string ret;
	for(char& ch : answer){
		if(!ret.empty() && ret.back() == '.' && ch == '.') continue;
		ret += ch;
	}
	answer = ret;
    //. ÷/�� ����
    
    if(answer[0] == '.') answer.erase(answer.begin());
    if(answer[answer.size()-1] == '.') answer.erase(answer.end() -1);
    
    //���ڿ� a����
    if(answer.empty()){
        answer = "a";
    }
    //16�̻��̸� 15���� ����
    if(answer.size() >= 16) answer = answer.substr(0,15);
    if(answer.back() == '.') answer.pop_back();
//    if(answer[answer.size()-1] == '.') answer.erase(answer.end() -1);
//    if(answer.length() >= 16){
//        answer.erase(15);
//        if(answer[answer.size()-1] == '.')answer.erase(answer.end() -1);
//    }
//    
    //2���ϸ� ������ ���ڷ� 3���� �ø���
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
