#include <iostream>
#include <list>
using namespace std;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	list<int> lst;
	for(int i = 1; i <= n; i++){
		lst.push_back(i);
	}

	cout << "<";
	auto cursor = lst.begin();
	
	while(lst.size() != 1){
		for(int i = 0; i < k-1; i++){
			cursor++;
			if(cursor == lst.end())
				cursor = lst.begin();
		}
		cout << *cursor << ", ";
		cursor = lst.erase(cursor);
		if(cursor == lst.end())
			cursor = lst.begin();
	}
	cout << *cursor << ">";
} 
