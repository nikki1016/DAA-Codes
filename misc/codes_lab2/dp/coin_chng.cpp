#include<stdio.h>
int main(){
	int m,n;
	scanf("%d",&m);
	int arr[m];
	int i;
	for(i=0;i<m;i++) {
		scanf("%d",&arr[i]);
	}
	scanf("%d",&n);
	int t[n+1];
	t[0]=1;
	int j;
	for(i=0;i<m;i++) {
		for(j=arr[i];j<=n;j++) {
			t[j]+=t[j-arr[i]];
		}
	}
	printf("%d\n",t[n]);
	return 0;
}
