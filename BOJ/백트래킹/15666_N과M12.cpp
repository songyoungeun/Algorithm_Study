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

void rec_func(int idx, int k){
	
	if(k == m + 1){		
		for(int i = 1; i <= m; i++){
			cout << selected[i]<<' ';
		}
		cout << '\n';
		return;
	}
	int last_cand = 0;

	for(int cand = idx; cand <= n; cand++){
		if(last_cand == nums[cand]) continue;
		last_cand = nums[cand];	
		selected[k] = nums[cand];
		rec_func(cand,k + 1);
		selected[k] = 0;
		
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	input();
	rec_func(1,1);
	return 0;
} 
