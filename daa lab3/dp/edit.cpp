#include<stdio.h>
#include<limits.h>
#include<string.h>
int min(int a,int b) {
	return a<b?a:b;
}
int main() {
	char x[10];
	char y[10];
	scanf("%s%s",x,y);
	int m=strlen(x);
	int n=strlen(y);
	int E[m+1][n+1];
	int i;
	int m1;
	for(i=0;i<=n;i++){
		E[0][i]=i;
	}
	for(i=0;i<=m;i++){
		E[i][0]=i;
	}
	int j;
	for(i=1;i<=m;i++) {
		for(j=1;j<=n;j++) {
			m1=min(E[i-1][j],E[i][j-1])+1;
			E[i][j]=min(m1,E[i-1][j-1]+(x[i-1]==y[j-1]?0:1));	
		}
	}
	printf("%d\n",E[m][n]);
	return 0;
}
