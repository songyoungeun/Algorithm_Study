#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

//�̷��� �Լ��� ���� ������ ����  
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
        bool flag = false; // ����µ� �ݴ°�ȣ ���� ���ð�� ������ ���� ��
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
        /* ��ȣȸ�� */
        char c = s.front();
        s.erase(s.begin());
        s.push_back(c);
        //rotate(s.begin(),s.begin()+1,s.end());
        //begin ~ begin + 1 , ���ڿ� �� ����
		//end �ǵ� ���� ������!
    }
    return answer;
}
