#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    //윤년은 2월달이 29일까지 있는 해
    int month[] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
    string day[] = {"FRI","SAT","SUN","MON","TUE","WED","THU"};
    int num = b - 1; // 1일부터 b일까지 일수 더하 기  
    for(int i = 1; i < a; i++){
        num += month[i];
    }

    answer = day[num % 7];
    return answer;
}
