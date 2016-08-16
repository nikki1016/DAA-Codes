#include <stdio.h>

int main()
{
	long long int t,n;
	
	scanf("%lld",&t);
	
	while(t--) 
	{
		scanf("%lld",&n);
		if(n%2)
		printf("Bamboozled!\n");
		else
		printf("How you doin?\n");
	}
	return 0;
}
