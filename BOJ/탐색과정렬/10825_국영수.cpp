#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define NM 100005

int N;

struct Elem{
	string name;
	int korean, english, math;
	bool operator<(const Elem& rhs) const{ // &는 구조체 주소로 받아 속도 높임 
	//근데 주소 접근해 값 변경할 수 있는 취약점있어 그래서 const로 읽기 전용으로 선언 
	 
		if(korean != rhs.korean) return rhs.korean < korean; //내림차순  
		if(english != rhs.english) return english < rhs.english; //오름차순  
		if(math != rhs.math) return rhs.math < math; // 내림차순  
		return name < rhs.name; //이름  
	
	}
}a[NM];

void input(){
	cin >> N; 
	for(int i = 1; i <= N; i++){
		cin >> a[i].name >> a[i].korean >> a[i].english >> a[i].math;
	}
}
void pro(){
	sort(a + 1, a + 1 + N);
	for(int i = 1; i <= N; i++){
		cout << a[i].name << '\n';
	}
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	input();
	pro();
	return 0;
}
