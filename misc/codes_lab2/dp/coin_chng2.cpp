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
	int t[n+1][m];
	for(i=0;i<m;i++){
		t[0][i]=1;
	}
	int x,y,j;
	for(i=1;i<=n;i++) {
		for(j=0;j<m;j++) {
			x=(i-arr[j])>=0?t[i-arr[j]][j]:0;
			y=(j>=1)?t[i][j-1]:0;
			t[i][j]=x+y;
		}
	}
	printf("%d\n",t[n][m-1]);
	return 0;
}
