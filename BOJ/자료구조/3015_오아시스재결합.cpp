#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int n, height;
long long ans;
stack<pair<int,int>> s;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> height;
		//ūŰ
		//���� ����� Ű�� ������ top�� �ִ� ������� ũ��
		//�� ����� ���� ��� ���ķ� ���� �̷��� ���� 
		while(!s.empty() && height > s.top().first){
			ans += s.top().second;
			s.pop();
		}
		//�Ǿտ� ����� ����  
		if(s.empty())
			s.push({height,1});
		else{
			//����Ű
			if(s.top().first == height){
				int cur = s.top().second;
				s.pop();
				//���� �� ���� ū ����� ���̷�  
				if(!s.empty()) ans++;
				ans += cur;
				s.push({height,cur+1});
			}
			//����Ű
			else{
				ans += 1;
				s.push({height,1});
			} 
		}
	}
	cout << ans;
}
