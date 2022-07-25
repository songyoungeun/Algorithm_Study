#include <iostream>
#include<string>
using namespace std;

int solution(string s)
{
    int answer = -1;
    string res = "";
    for(char& str : s){
        // if(res.empty()){
        //     res.push_back(str);
        // }
        if(!res.empty() && res.back() == str){
            res.pop_back();
        }
        else{
            res.push_back(str);
        }
        
    }
    if(res.empty()) answer = 1;
    else answer = 0;

    return answer;
}
