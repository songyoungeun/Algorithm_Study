#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(string a, string b){
    return a+b > b+a;
}
string solution(vector<int> numbers) {
    string answer = "";
    vector<string> num;
    for(auto a: numbers)num.push_back(to_string(a));
    sort(num.begin(),num.end(),cmp);
    for(auto tmp : num){
        answer += tmp;
    }
    return answer;
}
