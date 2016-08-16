#include <stdio.h>
#include <math.h>

int findTrailingZeros(int  n)
{
    int count = 0;
    int i;
    for (i=5; n/i>=1; i *= 5)
          count += n/i;
 
    return count;
}
int main()
{
	int t,a,i;
	scanf("%d",&t);
	i = 1;
	while(t--){
	double k;
	scanf("%lf",&k);
	
	double m = 4*k;
	long long int n = m;
	a = n%5;
	f = 0;
	n =  n + (5-a);
	for(;n<1000000000000000000;n++)
	if(findTrailingZeros(n) == k){
		f = 1;
		break;
	}
	
	}
	return 0;
}
