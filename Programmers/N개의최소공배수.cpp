#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int Gcd(int a, int b){ // ��Ŭ���� ȣ����, �ִ����� ���ϱ�  
	int x = max(a, b);
	int y = min(a, b);
	
	while(x % y != 0){
		int r = x % y;
		x = y;
		y = r;
	}
	return y;
}
int solution(vector<int> arr) {
    int answer = arr[0];
    for(int i = 1; i < arr.size(); i++){
        int gcd = Gcd(answer,arr[i]); //�ִ��������ϱ�
        int lcm = (answer * arr[i]) / gcd; //�ּҰ����= �� ���� �� / �ִ�����
        answer = lcm;
    }
    return answer;
}

// �ּҰ���� = �� ���� �� / �ִ� �����
//n���� �ּҰ���� ���ϱ��: 
//[ A , B , C , D ] �� ���� �� �� A, B, C, D�� �ּҰ������ �󸶰� �ɱ� ???
//2���� ��� ���� ���� �ִ�.
//A�� B�� �ּҰ���� = x
//x�� C�� �ּҰ���� = y
//y�� D�� �ּҰ���� = z
//A, B, C, D�� �ּҰ������ 'z'�� �ȴٴ� ��
