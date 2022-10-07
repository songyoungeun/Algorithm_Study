#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int N, L;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> L;
	vector<int> arr(N);
	for(int i = 0; i < N; i++){
		cin >> arr[i];
	}
	
	deque<pair<int,int>> dq; //data,pos
	for(int i = 0; i < N; i++){
		if(!dq.empty() && i == dq.front().second + L) // 나갈타이밍이 된 건 앞에서 빠져나가도록
			dq.pop_front();
		while(!dq.empty() && dq.back().first > arr[i]) //arr[i]가 들어오게 됨으로써 arr[i]보다 커서 앞으로 최소값 될 일이 절대 없는 기존 deque안 원소는 삭제
			dq.pop_back();
		dq.push_back({arr[i],i});
		cout << dq.front().first << ' '; 
	}
}
