#include <iostream>
#include <algorithm>

using namespace std;

int student[30];
vector<int> ans;
void pro(){
	for(int i = 1; i <= 30; i++){
		if(student[i] == 0){
			ans.push_back(i);
		}
	}
	sort(ans.begin(), ans.end());
	for(int i : ans){
		cout << i << '\n';
	}
}
void input(){
	for(int i = 1; i <= 28; i++){
		int a;
		cin >> a;
		student[a]++;
	}
	pro();
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	input();
}
