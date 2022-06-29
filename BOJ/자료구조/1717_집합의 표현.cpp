#include <iostream>
using namespace std;

int n, m;
int parent[1000001];

int getParent(int x){
	if(parent[x] == x) return x;
	return parent[x] = getParent(parent[x]);
}
void unionParent(int a, int b){
	a = getParent(a);
	b = getParent(b);
	if(a > b) parent[a] = b;
	else parent[b] = a;
}
void findParent(int a, int b){
	a = getParent(a);
	b = getParent(b);
	if(a == b) cout << "yes\n";
	else cout << "no\n";
}
void input(){
	
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++)
		parent[i] = i;
	 
	for(int i = 0; i < m; i++){
		int o, a, b;
		cin >> o >> a >> b;
		if(!o){
			unionParent(a, b);
		} 
		else{
			findParent(a, b);
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	input();
}
