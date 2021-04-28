#include <iostream>

using namespace std;

int n;
char tree[27][2];
//root -> �� ->  �� 
void preorder(int idx){
	if(idx + 'A' == '.') return;
	
	cout << (char)(idx + 'A');
	preorder(tree[idx][0] - 'A');
	preorder(tree[idx][1] - 'A');
	return;
}
//�� -> root -> �� 
void inorder(int idx){
	if(idx + 'A' == '.') return;
	
	inorder(tree[idx][0] - 'A');
	cout << (char)(idx + 'A');
	inorder(tree[idx][1] - 'A');
	return;
}
//�� -> �� -> root 
void postorder(int idx){
	if(idx + 'A' == '.') return;
	
	postorder(tree[idx][0] - 'A');
	postorder(tree[idx][1] - 'A');
	cout << (char)(idx + 'A');
	return;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	char a, b, c;
	while(n--){
		cin >> a >> b >> c;
		tree[a - 'A'][0] = b;
		tree[a - 'A'][1] = c;
	}
	preorder(0);
	cout << '\n';
	inorder(0);
	cout << '\n';
	postorder(0);
	cout << '\n';
		
} 
