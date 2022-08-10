#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int idx = -1;
    for(int i = 0; i < number.size() - k; i++){
        char max_chr = ' ';
        for(int j = idx + 1; j <= k + i; j++){
            if(max_chr < number[j]){
                max_chr = number[j];
                idx = j;
            }
        }
        answer += max_chr;
    }
    return answer;
    
//    answer = number.substr(k);
//	for(int i = k-1; i >= 0; i--){
//		int j = 0;
//		do{
//			if(number[i] >= answer[j]){
//				char temp = answer[j];
//				answer[j] = number[i];
//				number[i] = temp;
//				j++;
//			}
//			else break;
//		} while(1);
//	} 
}

