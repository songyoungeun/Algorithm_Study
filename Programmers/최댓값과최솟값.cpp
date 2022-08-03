#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
using namespace std;
vector<int> v;
string solution(string s) {
    string answer = "";
    int num;
    stringstream stream; 
    stream.str(s);
    while(stream >> num ){
        v.push_back(num);
    }

    sort(v.begin(),v.end());
    
    answer += to_string(v.front());
    answer += ' ';
    answer += to_string(v.back());
    return answer;
}
