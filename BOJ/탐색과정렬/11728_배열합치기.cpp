#include <iostream>
using namespace std;

int n,m;
int a[1000001],b[1000001],c[1000001];

int main(){
	scanf("%d%d", &n,&m);
	for(int i=0; i<n; i++) scanf("%d",&a[i]);
	for(int i=0; i<m; i++) scanf("%d",&b[i]);
	
	int aidx=0, bidx=0;
	for(int i=0; i<n+m; i++){
		if(bidx == m) c[i] = a[aidx++];
		else if(aidx == n) c[i] = b[bidx++];
		else if(a[aidx] <= b[bidx]) c[i] = a[aidx++];
		else c[i] = b[bidx++];
	}
	for(int i=0; i<n+m; i++){
		printf("%d ",c[i]);
	}
}
