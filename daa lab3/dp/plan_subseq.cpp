#include<stdio.h>
#include<string.h>
int max(int a,int b) {
	return a>b?a:b;
}
int main() {
	char s[100];
	scanf("%[^\n]s",s);
	//printf("%s",s);
	int cl,n,i;
	n=strlen(s);
	int l[n][n];
	for(i=0;i<n;i++) {
		l[i][i]=1;
	}
	int j;
	for(cl=2;cl<=n;cl++) {
		for(i=0;i<n-cl+1;i++) {
			j=i+cl-1;
			if(s[i]==s[j] && cl==2) l[i][j]=2;
			else if(s[i]==s[j]) l[i][j]=l[i+1][j-1]+2;
			else l[i][j]=max(l[i+1][j],l[i][j-1]);
		}
	}
	printf("%d\n",l[0][n-1]);
	return 0;
}
