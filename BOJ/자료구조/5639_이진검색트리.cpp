#include <iostream>

using namespace std;

struct NODE{
	int left,right;
}n[1000002];

void postorder(int rt){
	if(rt == 0) return;
	postorder(n[rt].left);
	postorder(n[rt].right);
	cout << rt << '\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int root;
	cin >> root;
	int num;
	while(cin >> num){
		int cur = root;
		while(1){
			if(num < cur){
				if(n[cur].left != 0) cur = n[cur].left;
				else{
					n[cur].left = num;
					break;
				}
			}
			else{
				if(n[cur].right != 0) cur = n[cur].right;
				else{
					n[cur].right = num;
					break;
				}
			}
		}
	}
	postorder(root);
	return 0; 
}
