#include<stdio.h>
#include <string.h>

int main()
{
	int t,l,i,j,c;
	char s[10005];
	scanf("%d",&t);
	while(t--){
		scanf("%s",&s);
		l = strlen(s);
		c = 0;
		for(i=1;i<l;i++){
			if(s[i]=='A'&&s[i-1]=='A') c++;
			else if(s[i]=='B'&&s[i-1]=='B') c++;
		}
		printf("%d\n",c);
	}
	return 0;
}
