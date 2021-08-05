#include <iostream>

using namespace std;

const int MX = 100005;
int dat[MX];
int pos = 0;

void push(int x){
	dat[pos++] = x;
}
int pop(){
	pos--;
}
int top(){
	return dat[pos-1];
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	while(n--){
		string str;
		cin >> str;
		if(str == "push"){
			int a;
			cin >> a;
			push(a);
		}
		else if(str == "pop"){
			if(pos == 0) // pos == 0이면 스택 비었음! 
				cout << -1 << '\n';
			else{
				cout << top() << '\n';
				pop();
			}
		}
		else if(str == "size"){
			cout << pos<< '\n';
		}
		else if(str == "empty"){
			cout << (int)(pos == 0) << '\n';
		}
		else{ //top
			if(pos == 0)
				cout << -1 <<'\n';
			else cout << top() << '\n';
		}
	}
}
