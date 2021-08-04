#include <iostream>
#include <list>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string str;
	cin >> str;
	list<char> L; 
	for(auto c : str) L.push_back(c);
	auto cur = L.end();
	int q;
	cin >> q;
	while(q--){
		char op;
		cin >> op;
		if(op == 'P'){
			char add;
			cin >> add;
			L.insert(cur,add);
		}
		else if(op == 'L'){
			if(cur != L.begin()) cur--;
		}
		else if(op == 'D'){
			if(cur != L.end()) cur++;
		}
		else{ //'B'
			if(cur != L.begin()){
				cur--;
				cur = L.erase(cur);
			}
		}
		
	}

	for(auto i : L) cout << i ;

}
