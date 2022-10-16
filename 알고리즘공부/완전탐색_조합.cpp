//����� ��
//- ����: ���� ������ ����� �����ħ (����� �ִ� ���� ū ���ڸ��� ���ϱ�)
//- ����: ���� ������ ����� ���� ���� (�� �� �������� ���� ū�� ���ϱ�) 
// ������ �������� ����� ���� ���� �ð� �� �ɸ�  
#include <iostream>
#include <algorithm>

using namespace std;

int n = 4;
int nums[] = {1,2,3,4};

int solve(int pos, int cnt, int val){

//	pos : ������ġ cnt : ���ð���
	if(cnt == 2) return val;
	if(pos == n) return -1; 
	int ret = 0;
	ret = max(ret, solve(pos + 1, cnt + 1, val + nums[pos])); //�����ϰ� 
	ret = max(ret, solve(pos + 1, cnt , val));  //���þ��ϰ� 
	
//	1 -> 2 :3
//	  -> - (���þ��ϰ�) -> 3 : 4
//	                    -> - (���þ��ϰ�) -> 4 :5 
	return ret;
}

int main(){
	cout << solve(0,0,0) <<'\n'; // ���� ū �μ��� �� ���ϱ�, ����  
	return 0;
}
 
