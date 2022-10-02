#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    int col_val = 0, row_val = 0; //Çà ¿­ °ª
    for(long long i = left; i <= right; i++){
        col_val = i / n;
        row_val = i % n;
        
        if(col_val >= row_val + 1){
            row_val += col_val - row_val;
        }
        answer.push_back(row_val + 1);
    }
    return answer;
}
