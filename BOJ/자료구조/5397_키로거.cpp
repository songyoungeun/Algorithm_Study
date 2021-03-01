#include <iostream>
#include <list>
#include <string>

using namespace std;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		string pw;
	  	cin>> pw;
	  	list<char> L;
	  	list<char>::iterator cursor = L.end();//커서 위치 

		for(auto c : pw){
			if(c == '<'){
				if(cursor != L.begin()) cursor--;	
			}
			else if(c == '>'){
				if(cursor != L.end()) cursor++;
			}
			else if(c == '-'){
				if(cursor != L.begin()){
				cursor--;
				cursor = L.erase(cursor);
				}
			}
			else{
				L.insert(cursor, c);// cursor의 왼편에 c추가  
			}
		} 
		for(auto c : L) cout<<c ;
		cout << '\n';
			
	}

}
