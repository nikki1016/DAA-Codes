#include<stdio.h>
#include<limits.h>
#include<string.h>
int min(float a,float b) {
	return a<b?a:b;
}
int main() {
	char x[10];
	char y[10];
	scanf("%s%s",x,y);
	int m=strlen(x);
	int n=strlen(y);
	float E[m+1][n+1];
	int i;
	int m1;
	//insertion 0.7
	//deletion 0.7
	//subsi 1
	for(i=0;i<=n;i++){
		E[0][i]=i*0.7;
	}
	for(i=0;i<=m;i++){
		E[i][0]=i*0.7;
	}
	int j;
	for(i=1;i<=m;i++) {
		for(j=1;j<=n;j++) {
			if(x[i-1]==y[j-1]) {
				E[i][j]=E[i-1][j-1];
			}else {
				E[i][j]=min(min(E[i-1][j-1]+1,E[i-1][j]+0.7),E[i][j-1]+0.7);
			}
		}
	}
	printf("%lf\n",E[m][n]);
	return 0;
}
