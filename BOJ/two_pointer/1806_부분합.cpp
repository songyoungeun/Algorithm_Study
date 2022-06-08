#include <iostream>
#include <algorithm>
using namespace std;

int n, s;
int num[100001];

void input(){
	cin >> n >> s;
	for(int i = 1; i <= n; i++)
		cin >> num[i];
}
void pro(){
	int R = 0, sum = 0, ans = n + 1;
	for(int L = 1; L <= n; L++){
		//L-1�� �������� �����ϱ�
		sum -= num[L-1];
		cout << "sum: " <<sum <<'\n'; 
		//R�� �ű� �� ���� �� ���� �ű��
		while(R + 1 <= n && sum < s){
			cout << "R: " << R <<'\n';
			sum += num[++R];
			cout << "while: " <<sum <<'\n'; 
			
		}

			
		//[L...R]�� ��, �� sum�� ������ �����ϸ� ���� �����ϱ� 
		if(sum >= s)
			ans = min(ans, R - L + 1);
	}
	if(ans == n + 1)
		ans = 0;
	cout << ans; 
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	input();
	pro();
}
