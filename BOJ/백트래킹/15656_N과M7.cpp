#include <iostream>
#include <algorithm>
using namespace std;

int n, m, selected[10], nums[10], used[10];

void input(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++)	
		cin >> nums[i];
	sort(nums + 1, nums + 1 + n);
}

void rec_func(int k){
	
	if(k == m + 1){		
		for(int i = 1; i <= m; i++){
			cout << nums[selected[i]]<<' ';
		}
		cout << '\n';
		return;
	}
	int last_cand = 0;
	for(int cand = 1; cand <= n; cand++){
		
		selected[k] = cand;
		rec_func(k + 1);
		selected[k] = 0;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	input();
	rec_func(1);
	return 0;
} 
