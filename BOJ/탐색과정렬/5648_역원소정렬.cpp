#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	vector<long long> ans;
	cin >> n;
	for(int i = 0; i < n; i++){
		string num;
		cin >> num;
		reverse(num.begin(), num.end());
		ans.push_back(stoll(num));
	}
	sort(ans.begin(),ans.end());
	for(int i = 0; i < n; i++){
		cout << ans[i] << '\n';
	}	
		
}

