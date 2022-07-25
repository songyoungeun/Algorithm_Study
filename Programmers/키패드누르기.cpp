#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int lefthand = 10, righthand = 12;
    for(int i = 0; i < numbers.size(); i++){
        if(numbers[i] % 3 == 1){
        	// numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7
            answer += "L";
            lefthand = numbers[i];
        }
        else if(numbers[i] % 3 == 0 && numbers[i] != 0){
            answer += "R";
            righthand = numbers[i];
        }
        else{
        	int Ldist = 0, Rdist = 0;
            if(numbers[i] == 0) numbers[i] = 11;
            int tmp_L = abs(lefthand - numbers[i]);
            int tmp_R = abs(righthand - numbers[i]);

            Ldist = tmp_L / 3 + tmp_L %3;
            Rdist = tmp_R / 3 + tmp_R %3;

            if(Ldist == Rdist){
                if(hand == "right"){answer += "R";righthand = numbers[i];}
                else{answer += "L";lefthand = numbers[i];} 
            }
            else if(Ldist < Rdist){
                answer += "L";
                lefthand = numbers[i];

            }
            else{
                answer += "R";
                righthand = numbers[i];

                
            }
        }
    }
    return answer;
}
