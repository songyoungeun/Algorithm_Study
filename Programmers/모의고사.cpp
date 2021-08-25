#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int one[5] = {1,2,3,4,5};
int two[8] = {2,1,2,3,2,4,2,5};
int three[10] = {3,3,1,1,2,2,4,4,5,5};

vector<int> solution(vector<int> answers) {
    vector<int> score(3);
    vector<int> ans;
    int mx_score = 0;
    for(int i = 0; i < answers.size(); i++){
        if(one[i%5] == answers[i]) score[0]++;
        if(two[i%8] == answers[i]) score[1]++;
        if(three[i%10] == answers[i]) score[2]++;
    }
    mx_score = max(max(score[0],score[1]),score[2]);
    for(int i = 0; i < 3; i++){
        if(score[i] == mx_score) ans.push_back(i+1);
    }
    return ans;
}
