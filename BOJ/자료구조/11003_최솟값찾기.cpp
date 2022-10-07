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
		if(!dq.empty() && i == dq.front().second + L) // ����Ÿ�̹��� �� �� �տ��� ������������
			dq.pop_front();
		while(!dq.empty() && dq.back().first > arr[i]) //arr[i]�� ������ �����ν� arr[i]���� Ŀ�� ������ �ּҰ� �� ���� ���� ���� ���� deque�� ���Ҵ� ����
			dq.pop_back();
		dq.push_back({arr[i],i});
		cout << dq.front().first << ' '; 
	}
}
