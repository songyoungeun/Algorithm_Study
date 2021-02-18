#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	stack<int> s;
	vector<int> v(80001);
	long long cnt = 0;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> v[i];


	for(int i = 0; i < n; i++){ 
		while(!s.empty() && s.top() <= v[i]) s.pop();
		cnt += (long long)s.size();
		s.push(v[i]);
	}cout <<cnt;
	
}
