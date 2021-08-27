
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int>ans;
    vector<int>days;
    queue<int>q;

    for(int i = 0; i < progresses.size(); i++){
        int d = (100 - progresses[i])/speeds[i];
        if(progresses[i] + d*speeds[i] != 100) d++;
        days.push_back(d);
    }
    q.push(days[0]);
    for(int i = 1; i < days.size(); i++){
        if(q.front() >= days[i]){
            q.push(days[i]);
        }
        else{
            ans.push_back(q.size());
            while(!q.empty()) q.pop();
            q.push(days[i]);
        }
    }
    if(!q.empty()) ans.push_back(q.size());

    return ans;
}
