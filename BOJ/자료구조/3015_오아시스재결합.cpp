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
		//큰키
		//현재 사람의 키가 스택의 top에 있는 사람보다 크면
		//이 사람은 현재 사람 이후로 쌍을 이루지 못해 
		while(!s.empty() && height > s.top().first){
			ans += s.top().second;
			s.pop();
		}
		//맨앞에 사람을 세움  
		if(s.empty())
			s.push({height,1});
		else{
			//같은키
			if(s.top().first == height){
				int cur = s.top().second;
				s.pop();
				//스택 내 제일 큰 사람과 쌍이룸  
				if(!s.empty()) ans++;
				ans += cur;
				s.push({height,cur+1});
			}
			//작은키
			else{
				ans += 1;
				s.push({height,1});
			} 
		}
	}
	cout << ans;
}
