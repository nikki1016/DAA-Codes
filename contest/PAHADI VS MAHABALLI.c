#include <stdio.h>

int main()
{
	int t;
	long long int k,m,n,f;
	scanf("%d",&t);
	while(t--){
		scanf("%lld",&k);
		f = 0;
		if(k==1) f = 0;
		else if(k==2) f = 1;
		else {
			m = k -2;
			n = m/7;
			if(n*7 == m) {
				f = 1;
			}
			else {
				m = k - 7;
				n = m/7;
				if(n*7 == m) f = 1;;
				}
		}
		if(f==1) printf("Mahabali Khali!\n");
		else printf("PAHADI!\n");	
	}
	return 0;
}
