#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int cnt = 0;
    int zero_num = 0;
    string n = "";

    while(s.length() > 1){
        int res = 0;
        for(char str : s){
            if(str == '1') res++;
            else zero_num++;    
        }
        cnt++;
        if(res == 1){
            break;
        }

        while(res){
            n += to_string(res % 2);
            res /= 2;
        }
        reverse(n.begin(), n.end());
        s = n;
        n = "";
        
    }
    
    answer.push_back(cnt);
    answer.push_back(zero_num);
    return answer;
}
