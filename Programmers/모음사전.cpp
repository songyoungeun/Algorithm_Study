#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<string> arr;
string tmp[5] = {"A","E","I","O","U"};

void func(int len, string str){
    if(len == str.size()){
        arr.push_back(str);
        return;
    }
    for(int i = 0; i < 5; i++){
        func(len, str + tmp[i]);
    }
}
int solution(string word) {
    int answer = 0;

    for(int i = 1; i <= 5; i++){
        func(i,"");
    }
    sort(arr.begin(),arr.end());
   
    answer = find(arr.begin(),arr.end(),word) - arr.begin() + 1;
    return answer;
}
