#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    //������ 2������ 29�ϱ��� �ִ� ��
    int month[] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
    string day[] = {"FRI","SAT","SUN","MON","TUE","WED","THU"};
    int num = b - 1; // 1�Ϻ��� b�ϱ��� �ϼ� ���� ��  
    for(int i = 1; i < a; i++){
        num += month[i];
    }

    answer = day[num % 7];
    return answer;
}
