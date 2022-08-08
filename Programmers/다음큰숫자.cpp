#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    int tmp  = n;
    string str = "";
    while(tmp >= 1){
        if(tmp % 2 == 1) str += "1";
        tmp /= 2;
    }
    int len = str.size();
    cout << len <<'\n';
    while(1){
        string y = "";
        n++;
        int x = n;
        while(x >= 1){
            if(x % 2 == 1) y += "1";
            x /= 2;
        }
        if(y.size() == len){
        	answer = n;
        	break;
		}
    }
    
    return answer;
}

//bitset사용 .count : 비트 1의 갯수 
//int main(){
//	int n = 78;
//	cout << bitset<20>(n);
//    int num = bitset<20>(n).count();
//
//    while (bitset<20>(++n).count() != num);
//    return n;
//} 
