#include <iostream>

using namespace std;

int now[3], start[3], res[3];

int main(){
	scanf("%d:%d:%d",&now[0],&now[1],&now[2]);
	scanf("%d:%d:%d",&start[0],&start[1],&start[2]);
	//ÃÊ 
	if(start[2] >= now[2]){
		res[2] = start[2] - now[2];	
	}
	else{
		res[2] = 60 + start[2] - now[2];
		start[1]--;
	}
	//ºĞ  
	if(start[1] >= now[1]){
		res[1] = start[1] - now[1];	
	}
	else{
		res[1] = 60 + start[1] - now[1];
		start[0]--;
	}
	//½Ã  
	if(start[0] >= now[0]){
		res[0] = start[0] - now[0];	
	}
	else{
		res[0] = 24 + start[0] - now[0];
	}
	if(res[0] == 0 && res[1] == 0 && res[2] == 0) res[0] = 24;
	printf("%02d:%02d:%02d",res[0],res[1],res[2]);
	return 0;
}
