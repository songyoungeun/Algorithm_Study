//����� ��
//- ����: ���� ������ ����� �����ħ (����� �ִ� ���� ū ���ڸ��� ���ϱ�)
//- ����: ���� ������ ����� ���� ���� (�� �� �������� ���� ū�� ���ϱ�) 

#include <iostream>
#include <algorithm>

using namespace std;

int n = 4;
int nums[] = {1,2,3,4};

int solve(int cnt, int used, int val){

	if(cnt == 2) return val; // �μ� ���������  
	int ret = 0;

	for(int i = 0; i < n; ++i){ //��� ����� ��  

		if(used & (1 << i)) continue;

		ret = max(ret, solve(cnt + 1, used | (1 << i), val * 10 + nums[i]));
		
	}
//	1 - 2,3,4
//	2 - 1,3,4
//	3 - 1,2,4
//	4 - 1,2,3
	return ret;
}

int main(){
	cout << solve(0,0,0) <<'\n'; // ���� ū ���ڸ��� ���ϱ� ,���� 
	return 0;
}
 
