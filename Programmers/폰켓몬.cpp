#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    set<int> s(nums.begin(), nums.end());
    
    int len = nums.size() / 2;
//    if(len == s.size())
//        answer = s.size();
//    else if(len < s.size())
//        answer = len;
//    else
//        answer = s.size();
    
    return min(nums.size() / 2, s.size());
}
