#include <iostream>
#include <algorithm>
#include <vector> 
using namespace std;

int start, e, n, t, big, small;
int a[100001];
bool search(int); //이분탐색 

int main(){
	
	scanf("%d",&n);
	
	for(int i=0; i<n; i++){
		scanf("%d",&a[i]);
	}
	sort(a, a+n);
	small = a[0];
	big = a[n-1];
	
	scanf("%d",&t);
	
	for(int i=0; i<t; i++){
		int ob;
		scanf("%d",&ob);
		
		if(ob == small || ob == big){printf("1\n"); continue;	}
		if(ob > big || ob < small ){printf("0\n"); continue;	}
		
		start = 0; e = n-1;
//		 s = 첫번째 인덱스 e= 마지막 인덱 스 
		printf("%d\n",search(ob));

		
	}
	return 0;
}

bool search(int k){
	int m = 0; // m = 중간 인덱스 
	while(e - start >= 0){
		m = (e + start) / 2;
		
		if(a[m] == k) {return true;}
		else if(a[m] < k ){ start = m + 1;}
		else{ e = m - 1;		}
	}
	return false;
}

//binary_search(first, last, key) 함수
int n, t;

vector<int> a;


int main(){
	
	scanf("%d",&n);
	a.resize(n);
	
	for(int i=0; i<n; i++){
		scanf("%d",&a[i]);
	}
	sort(a.begin(), a.end());
	
	scanf("%d",&t);
	
	for(int i=0; i<t; i++){
		int ob;
		scanf("%d",&ob);
		
		printf("%d\n", binary_search(a.begin(),a.end(), ob));
		
	}
	return 0;
}


