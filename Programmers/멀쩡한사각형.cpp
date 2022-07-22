#include <iostream>
using namespace std;

int gcd(int& w, int& h){ //최대공약수 구하기
    int c;
    while(h != 0){
        c = w % h;
        w = h;
        h = c;
    }
    cout << w;
    return w;
}
long long solution(int w,int h) {
    long long answer = 1;
    answer = (long long)w  * (long long)h - (w+h);
    answer += gcd(w,h);

    return answer;
}
