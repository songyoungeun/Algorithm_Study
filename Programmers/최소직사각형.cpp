#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
   	int x = 0, y = 0;
	for(int i = 0; i < sizes.size(); i++){
		x = max(x, max(sizes[i][0], sizes[i][1]));
		y = max(y, min(sizes[i][0], sizes[i][1]));
	} 
	answer = x * y;
    return answer;
}
