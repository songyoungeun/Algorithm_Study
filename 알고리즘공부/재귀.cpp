//재귀함수
//예> 팩토리얼
n = 0일 경우, n! = 1
n > 0일 경우, n! = n * (n - 1)!

int factorial(int n){
	if(n == 0)return 1;
	
	return n * factorial(n - 1);
} 
//함수 호출은 stack 메모리에 생성됨 코스가 아닌
//함수실행에 필요한 로컬변수, 리턴 어드레스

 
