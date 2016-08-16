#include <stdio.h>

int main()
{
	int t;
	long long int k,m,n;
	scanf("%d",&t);
	while(t--){
		scanf("%lld",&k);
		if(k==1) printf("PAHADI!\n");
		else if(k==2) printf("Mahabali Khali!\n");
		else {
			m = k -2;
			n = m/4;
			if(n*4==m) printf("Mahabali Khali!\n");
			else printf("PAHADI!\n");
		}			
	}
	return 0;
}
