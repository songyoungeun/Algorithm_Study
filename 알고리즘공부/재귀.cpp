//����Լ�
//��> ���丮��
n = 0�� ���, n! = 1
n > 0�� ���, n! = n * (n - 1)!

int factorial(int n){
	if(n == 0)return 1;
	
	return n * factorial(n - 1);
} 
//�Լ� ȣ���� stack �޸𸮿� ������ �ڽ��� �ƴ�
//�Լ����࿡ �ʿ��� ���ú���, ���� ��巹��

 
