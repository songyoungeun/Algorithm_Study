#include <iostream>
using namespace std;

int n, m, selected[10], vis[10];

void input(){
	cin >> n >> m;
}

void rec_func(int k){
	
	if(k == m + 1){		
		for(int i = 1; i <= m; i++){
			cout << selected[i] <<' ';
		}
		cout << '\n';
		return;
	}

	for(int cand = selected[k-1] + 1; cand <= n; cand++){
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
