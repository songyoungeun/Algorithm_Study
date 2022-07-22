#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int used[101];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	fill(used, used + 101 , -1);
	
	int n; cin >> n;
	int ans = 0;
	for(int i = 0; i < n; i++){
		int num, loc;
		cin >> num >> loc;
		if(used[num] < 0) used[num] = loc;
		else if(used[num] != loc){
			used[num] = loc;
			ans++;
		}
	}

	cout << ans;
}
