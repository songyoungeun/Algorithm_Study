#include <iostream>
#include <queue>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	priority_queue<int> maxhp;
	priority_queue<int, vector<int>, greater<int>> minhp;
	cin >> n;
	while(n--){
		int num;
		cin >> num;
		if(maxhp.size() == 0){
			maxhp.push(num);
		}
		else{
			if(maxhp.size() > minhp.size()){
				minhp.push(num);
			}
			else{
				maxhp.push(num);
			}
			if(maxhp.top() > minhp.top()){
				int maxtop = maxhp.top();
				int mintop = minhp.top();
				maxhp.pop();
				minhp.pop();
				maxhp.push(mintop);
				minhp.push(maxtop);
			}
		}
		cout << maxhp.top() << '\n';
	}
	
} 
