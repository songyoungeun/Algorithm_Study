#include <iostream>
#include <string>
using namespace std;

const int MX = 1000005;
int dat[2*MX+1];
int head = MX, tail = MX;

void push_front(int x){
	dat[--head] = x;
}
void push_back(int x){
	dat[tail++] = x;
}
void pop_front(){
	head++;
}
void pop_back(){
	tail--;
}

int front(){
	return dat[head];
}
int back(){
	return dat[tail-1];
}
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	while(n--){
		string d;
		cin>> d;
		if(d == "push_front"){
			int a;
			cin>>a;
			push_front(a);
		}
		else if(d=="push_back"){
			int b;
			cin>>b;
			push_back(b);
		}
		else if(d== "pop_front"){
			if(tail == head) 
				cout<< -1 << '\n';
			else{
				cout<<front() << '\n';
				pop_front();
			}
		}
		else if(d== "pop_back"){
			if(tail == head) 
				cout<< -1 << '\n';
			else{
				cout<<back() << '\n';
				pop_back();
			}
		}
		else if(d== "size"){
			cout << tail-head << '\n' ;
		}
		else if(d== "empty"){
			cout<< (tail==head)<< '\n';
		}
		else if(d== "front"){
			if(tail == head) 
				cout<< -1 << '\n';
			else cout<< front()<< '\n';
		}
		else {
			if(tail == head) 
				cout<< -1 << '\n';
			else cout<< back()<< '\n';
		}
		
	}
}
