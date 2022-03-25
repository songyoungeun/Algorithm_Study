#include <iostream>
#include <vector>

using namespace std;

// 0 <= node <= 10000
int tree[10000];
void postOrder(int start, int end){
	
	if(start >= end){
		return;
	}
	if(start == end - 1){
		cout << tree[start] << '\n';
		return;
	}
	int idx = start + 1;
	while(idx < end){
		if(tree[start] < tree[idx]){
			break;
		}
		idx++;
	}
	postOrder(start + 1, idx);
	postOrder(idx, end);
	cout <<tree[start] << '\n';

}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int num;
	int inputidx = 0;
	while(cin >> num){
		tree[inputidx++] = num;
	}

	postOrder(0,inputidx);
	
	return 0; 
} 
