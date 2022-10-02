#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

//이렇게 함수로 따로 빼서도 가능  
//bool isCorrect(string str) {
//    stack<char> st;
//    for(int i = 0; i < str.size(); i++) {
//        if(str[i] == '(' || str[i] == '{' || str[i] == '[') {
//            st.push(str[i]);
//        } else {
//            if(st.empty()) return false;
//            else {
//                if(st.top() == '(' && str[i] == ')') st.pop();
//                else if(st.top() == '{' && str[i] == '}') st.pop();
//                else if(st.top() == '[' && str[i] == ']') st.pop();
//            }
//        }
//    }
//    if(!st.empty()) return false;
//    return true;
//}



int solution(string s) {
    int answer = 0;
    
    for(int i = 0; i < s.length(); i++){
        stack<char> ss;
        bool flag = false; // 비었는데 닫는괄호 먼저 들어올경우 때문에 변수 둠
        for(char c : s){
            if(c == '(' || c == '[' || c == '{'){
                flag = true;
                ss.push(c);
            }
            else{
            	if(ss.empty()) break; 
                if(c == ')' && ss.top() == '('){
                    ss.pop();
                }
                if(c == ']' && ss.top() == '['){
                    ss.pop();
                }
                if(c == '}' && ss.top() == '{'){
                    ss.pop();
                }
            }
            
        }
        if(ss.empty() && flag) answer++;
        /* 괄호회전 */
        char c = s.front();
        s.erase(s.begin());
        s.push_back(c);
        //rotate(s.begin(),s.begin()+1,s.end());
        //begin ~ begin + 1 , 문자열 맨 앞을
		//end 맨뒤 으로 보낸다!
    }
    return answer;
}
