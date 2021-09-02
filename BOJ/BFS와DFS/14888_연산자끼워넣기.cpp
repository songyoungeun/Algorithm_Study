#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1000000000 + 1;
int n;
int num[12];
int op[4];
int maxres = -MAX, minres = MAX;

void dfs(int plus, int sub, int mul, int div, int cnt, int sum){
	//연산자를 모두 사용하였을 경우
	cout << "1 " <<'\n'; 
	if(cnt == n){
		maxres = max(maxres,sum);
		minres = min(minres,sum);
		cout << "A: " << maxres<< ' '<< minres<< sum <<'\n';
	} 
	if(plus > 0){
		cout << "+: " << num[cnt]<<'\n';
		dfs(plus-1, sub, mul, div, cnt+1, sum + num[cnt]);
	}
	if(sub > 0){
		cout << "-: " << num[cnt]<<'\n';
		dfs(plus, sub-1, mul, div, cnt+1, sum - num[cnt]);
	}
	if(mul > 0){
		cout << "*: "<< num[cnt] <<'\n';
		dfs(plus, sub, mul-1, div, cnt+1, sum * num[cnt]);
	}
	if(div > 0){
		cout << "/: "<< num[cnt] <<'\n';
		dfs(plus, sub, mul, div-1, cnt+1, sum / num[cnt]);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> num[i];
	}
	for(int i = 0; i < 4; i++)
		cin >> op[i];
	dfs(op[0],op[1],op[2],op[3],1,num[0]);
	cout << maxres << '\n';
	cout << minres;
		
}
