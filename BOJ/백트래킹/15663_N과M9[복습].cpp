#include <iostream>
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
			cout << selected[i] <<' ';
		}
		cout << '\n';
		return;
	}
	int last_cand = 0;
	for(int cand = 1; cand <= n; cand++){
		if(used[cand] == 1) continue;
		if(nums[cand] == last_cand) continue;
		
		last_cand = nums[cand];
		selected[k] = nums[cand], used[cand] = 1;
		rec_func(k + 1);
		selected[k] = 0, used[cand] = 0;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	input();
	rec_func(1);
	return 0;
} 
