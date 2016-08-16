#include<stdio.h>
#include<limits.h>
int main(){
	int n,i;
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++) {
		scanf("%d",&arr[i]);
	}
	int m[n][n];
	int l,j,k,q;
	for(i=1;i<n;i++) {
		m[i][i]=0;
	}
	for(l=2;l<n;l++) {
		for(i=1;i<=n-l+1;i++) {
			j=i+l-1;
			m[i][j]=INT_MAX;
			for(k=i;k<j;k++) {
				q=m[i][k]+m[k+1][j]+arr[i-1]*arr[k]*arr[j];
				if(q<m[i][j]) {
					m[i][j]=q;
				}
			}
		}
	}
	printf("%d\n",m[1][n-1]);
	return 0;
}
