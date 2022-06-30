#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

vector<int> t1;
vector<int> t2;
int ans[3];
void pro(){

	//second
	if(t2[2] >= t1[2]){
		ans[2] = t2[2] - t1[2];
	}
	else{
		ans[2] = 60 + t2[2] - t1[2];
		t2[1]--;
	}

//	//minute
	if(t2[1] >= t1[1]){
		ans[1] = t2[1] - t1[1];
	}
	else{
		ans[1] = 60 + t2[1] - t1[1];
		t2[0]--;
	}
//	//hour
	if(t2[0] >= t1[0]){
		ans[0] = t2[0] - t1[0];
	}
	else{
		ans[0] = 24 + t2[0] - t1[0];
	}
	//다음날 같은 시간일 경우 고려해야함!!! 
	if(ans[0] == 0 && ans[1] == 0 && ans[2] == 0) ans[0] = 24;
	//answer
	if(ans[0] < 10){
		cout << 0;
	}
	cout << ans[0] << ":";
	
	if(ans[1] < 10){
		cout << 0;
	} 
	cout << ans[1] << ":";
	
	if(ans[2] < 10){
		cout << 0;
	}
	cout << ans[2];
}
void input(){
	
	string now, start;
	cin >> now;
	for(int i = 0; i < now.size(); i++){
		if(now[i] == ':') now[i] = ' ';
	}
	cin >> start;
	for(int i = 0; i < start.size(); i++){
		if(start[i] == ':') start[i] = ' ';
	}

	int num = 0;
	stringstream stream1, stream2;
	stream1.str(now);
	while(stream1 >> num){
		t1.push_back(num);
	}
	stream2.str(start);
	while(stream2 >> num){
		t2.push_back(num);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	input();
	pro();
	return 0;
}
