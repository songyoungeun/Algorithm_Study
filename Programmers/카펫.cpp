#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int>ans;
    int sum = brown + yellow;
    for(int height = 3; height < sum; height++){
        if(sum%height == 0){
            int weight = sum / height;
            if((weight-2) * (height-2) == yellow){
                ans.push_back(weight);
                ans.push_back(height);
                break;
            }

        }
    }
    return ans;
}
