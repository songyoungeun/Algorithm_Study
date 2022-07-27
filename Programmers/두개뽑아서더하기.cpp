#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<int> solution(vector<int> numbers) {
//    sort(numbers.begin(), numbers.end());
    vector<int> answer;
    set<int> s;
    int ans = 0;
    for(int i = 0; i < numbers.size() - 1; i++){
        for(int j = i + 1; j < numbers.size(); j++){
            ans = numbers[i] + numbers[j];
            s.insert(ans);
        }
    }
    answer.assign(s.begin(),s.end()); //특정원소로 채우기 
//    for(auto k : s) answer.push_back(k);
    return answer;
}
