#include <iostream>
#include <stack>
using namespace std;
#define index first 
#define height second
int arr[500001];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, h;
	cin >> n;

	stack<pair<int,int>> s;
	for(int i = 0; i < n; i++){
		cin >> h;
		while(!s.empty()) {
			if(h < s.top().height){
				cout << s.top().index +1 << ' ';
				break;
			}
			s.pop();
		}
		if(s.empty()) cout << 0 <<' ';
		s.push({i,h});
	}

}
