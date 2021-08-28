#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(vector<int> priorities, int location) {
    queue<int>q;
    vector<int>sorted;
    for(int i = 0; i < priorities.size(); i++){
        q.push(i);
    }
    while(!q.empty()){
        int idx = q.front(); q.pop();
        if(priorities[idx] != *max_element(priorities.begin(),priorities.end())){
            q.push(idx);
        }
        else{
            priorities[idx] = 0;
            sorted.push_back(idx);
        }
    }
    for(int i = 0; i < sorted.size(); i++){
        if(sorted[i] == location)
            return i+1;
    }
}
