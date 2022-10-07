#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    for(int i = 0; i < land.size()-1; i++){
        land[i+1][0] += max(land[i][1],max(land[i][2],land[i][3]));
        land[i+1][1] += max(land[i][0],max(land[i][2],land[i][3]));
        land[i+1][2] += max(land[i][0],max(land[i][1],land[i][3]));
        land[i+1][3] += max(land[i][0],max(land[i][1],land[i][2]));
    }
    answer =  *max_element(land[land.size() - 1].begin(), land[land.size() - 1].end());

    return answer;
}
