#include <iostream>
#include <stack>

using namespace std;

int n;
string str;
int alpha[26];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	cin >> str;
	for(int i = 0; i < n; i++){
		cin >> alpha[i];
	}
	stack<double>s;
	for(int i = 0; i < str.length(); i++){
		if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/'){ 
			double a = s.top();
			s.pop();
			double b = s.top();
			s.pop(); 
			
			switch(str[i]){
				case '+':
					s.push(b + a);
					break;
				case '-':
					s.push(b - a);
					break;
				case '*':
					s.push(b * a);
					break;
				case '/':
					s.push(b / a);
					break;
				
			} 
		}
		else{
			s.push(alpha[str[i] - 'A']);			
		}
	}
	double res = s.top();
	cout << fixed; //�Ҽ��� �Ʒ� �� ���� 
	cout.precision(2); // �Ҽ��� �Ʒ� 2�� ���� , �ڸ��� ����  
	cout << res;
	
	return 0;

		
}
