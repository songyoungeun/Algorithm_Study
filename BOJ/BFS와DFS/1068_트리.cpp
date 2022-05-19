#include <iostream>
#include <vector>
using namespace std;

int n, root, del;
vector<int> node[55];
int leaf[55];

void input(){
	cin >> n;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		if(x == -1){
			root = i;
		}
		else{
			node[x].push_back(i);
		}	
	}
	cin >> del;
}

void dfs(int x, int par){
	if(node[x].empty())
		leaf[x]++;
		
	for(int y : node[x]){
		if(y == par) continue;
		dfs(y, x);
		leaf[x] += leaf[y];
	}
}


void pro(){
	for(int i = 0; i < n; i++){
		for(auto it = node[i].begin(); it != node[i].end(); it++){
			if(*it == del){
				node[i].erase(it);
				break;
			}
		}
	}
	if(root != del) dfs(root,-1);
	cout << leaf[root];
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	input();
	pro();
}
