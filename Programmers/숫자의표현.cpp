#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 1;
    int num = (n + 1) / 2;
    int sum = 0, j = 1;
    for(int i = 1; i <= num; i++){
        //������ �ڿ��� ���̱⿡ ����
        sum += i;
        if(sum >= n){
            while(sum > n) sum -= j++;
            if(sum == n) answer++;
        }
    }
    //�̹� answer�� 1�� ������� ���� 
    if(n == 1) answer = 1;
    return answer;
}
